#include <Wire.h>
#include <Servo.h>

#include <adk.h>

#if defined(LED_BUILTIN)
#define LED LED_BUILTIN // Use built in LED
#else
#define LED 9 // Set to something here that makes sense for your board.
#endif

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
ADK acc(&Usb, "Romain Baud", // Manufacturer Name
              "AndroCopterADK", // Model Name
              "AndroCopter ADK board", // Description (user-visible string)
              "1.0", // Version
              "randroprog.blogspot.com", // URL (web page to visit if no installed apps support the accessory)
              "0000000012345678"); // Serial Number (optional)

uint32_t timer;
bool connected;

#define  LED_PIN  13

const int BATTERY_LEVEL_PIN = A0;
const int NW_PWM_PIN = 4;
//const int NW_GND_PIN = 4;
const int NE_PWM_PIN = 5;   
//const int NE_GND_PIN = 7;
const int SE_PWM_PIN = 6;
//const int SE_GND_PIN = 9;
const int SW_PWM_PIN = 7;
//const int SW_GND_PIN = 12;

const int PULSE_MIN = 1000; // Min time of a pulse sent to an ESC [us].
const int PULSE_MAX = 2000; // Max time of a pulse sent to an ESC[us].
const unsigned long MAX_TIME_WITHOUT_RECEPTION = 500; // If no data is received during this time, stop all motors [ms].
const unsigned long PULSES_PERIOD = 2222; // Period of the main loop (450 Hz) [us].
const unsigned int BATT_VOLT_TX_PERIOD = 1000; // Sending period of the battery voltage [ms].

Servo nwMotor, neMotor, seMotor, swMotor;
int nwPower, nePower, sePower, swPower; // Impulses duration.
unsigned long currentTimeMs, lastRxTimeMs, lastTxTimeMs, lastPulseTimeUs, currentPulseTimeUs;
uint8_t rxBuffer[4];
uint16_t len = sizeof(rxBuffer);
uint8_t rcode;

void setup()
{
  // Setup the serial communication with the computer (debug).
    Serial.begin(115200);
    
    #if !defined(__MIPSEL__)
      while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
    #endif
    if (Usb.Init() == -1) {
      Serial.print("\r\nOSCOKIRQ failed to assert");
      while (1); // halt
    }
    pinMode(LED, OUTPUT);
    Serial.print("\r\nArduino Blink LED Started");

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN,LOW);
  
    // Variables init.
    currentTimeMs = millis();
    lastRxTimeMs = currentTimeMs;
    lastTxTimeMs = currentTimeMs;
    lastPulseTimeUs = micros();
  
    nwPower = PULSE_MIN;
    nePower = PULSE_MIN;
    sePower = PULSE_MIN;
    swPower = PULSE_MIN;
  
    // Associate the Servo objects to the pins.
    nwMotor.attach(NW_PWM_PIN);
    neMotor.attach(NE_PWM_PIN);
    seMotor.attach(SE_PWM_PIN);
    swMotor.attach(SW_PWM_PIN);
  
    // Set the GND pins for each ESC.
    //pinMode(NW_GND_PIN, OUTPUT); digitalWrite(NW_GND_PIN, LOW);
    //pinMode(NE_GND_PIN, OUTPUT); digitalWrite(NE_GND_PIN, LOW);
    //pinMode(SE_GND_PIN, OUTPUT); digitalWrite(SE_GND_PIN, LOW);
    //pinMode(SW_GND_PIN, OUTPUT); digitalWrite(SW_GND_PIN, LOW);
}

void loop()
{
  Usb.Task();
  currentTimeMs = millis();
  
  // Check if the phone is connected.
  if (acc.isReady()) // Yes, try to read it.
  {
    
    len = sizeof(rxBuffer);
    rcode = acc.RcvData(&len, rxBuffer);

    Serial.println(rxBuffer[0]);
    //Serial.print(rxBuffer[1]+"\n");

    if(len == 4)
    {
      // Update the motor signals.
      // The received powers for the motors (data[]) are between 0 and 255, so
	  // a transformation to the ESC range (1000-2000 us) is performed.
      nwPower = map(rxBuffer[0], 0, 255, PULSE_MIN, PULSE_MAX);
      nePower = map(rxBuffer[1], 0, 255, PULSE_MIN, PULSE_MAX);
      sePower = map(rxBuffer[2], 0, 255, PULSE_MIN, PULSE_MAX);
      swPower = map(rxBuffer[3], 0, 255, PULSE_MIN, PULSE_MAX);
    
      lastRxTimeMs = currentTimeMs;

      if((rxBuffer[0]==1)&(rxBuffer[1]==0)&(rxBuffer[2]==0)&(rxBuffer[3]==0))
      {
          digitalWrite(LED_PIN,LOW);
      }else{
          digitalWrite(LED_PIN,HIGH);  
      }

            
    }
  }
  else // Phone disconnected: emergency stop!
  {
    digitalWrite(LED_PIN,LOW);
    nwPower = PULSE_MIN;
    nePower = PULSE_MIN;
    sePower = PULSE_MIN;
    swPower = PULSE_MIN;
  }
  
  // If the phone does not send updates for some time, this mean
  // something could have go wrong (maybe the app crashed...), and
  // all motors must be stopped.
  if(currentTimeMs - lastRxTimeMs > MAX_TIME_WITHOUT_RECEPTION)
  {
    nwPower = PULSE_MIN;
    nePower = PULSE_MIN;
    sePower = PULSE_MIN;
    swPower = PULSE_MIN;
  }
  
  // Send a pulse to each ESC.
  nwMotor.writeMicroseconds(nwPower);
  neMotor.writeMicroseconds(nePower);
  seMotor.writeMicroseconds(sePower);
  swMotor.writeMicroseconds(swPower);
  
  // Sometimes, send the battery level to the phone.
  if(currentTimeMs - lastTxTimeMs >= BATT_VOLT_TX_PERIOD)
  {
    lastTxTimeMs = currentTimeMs;
    uint16_t batteryLevel = analogRead(BATTERY_LEVEL_PIN);
    //acc.write((uint8_t*)&batteryLevel, 2);
    acc.SndData(sizeof(batteryLevel), (uint8_t*)&batteryLevel);
  }
  
  // Delay to get a 450 Hz main loop.
  currentPulseTimeUs = micros();
  delayMicroseconds(PULSES_PERIOD - (currentPulseTimeUs - lastPulseTimeUs));
  lastPulseTimeUs = currentPulseTimeUs;
}
