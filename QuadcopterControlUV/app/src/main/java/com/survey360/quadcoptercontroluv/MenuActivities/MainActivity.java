package com.survey360.quadcoptercontroluv.MenuActivities;

import android.app.ActionBar;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.os.Build;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewConfiguration;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.PopupWindow;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.survey360.quadcoptercontroluv.R;
import com.survey360.quadcoptercontroluv.Utils.PermissionsRequest;

import java.lang.reflect.Field;

public class MainActivity extends AppCompatActivity {

    PermissionsRequest mPermissions = null;

    private Button bt_info, bt_settings, bt_mission, bt_tests;
    private PopupWindow popupWindow;
    private LayoutInflater layoutInflater;
    private RelativeLayout relativeLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);

        mPermissions = new PermissionsRequest(this, this);
        mPermissions.LocationPermission();

        getOverflowMenu();

        bt_info = (Button) findViewById(R.id.bt_Info);
        bt_settings = (Button) findViewById(R.id.bt_Settings);
        bt_tests = (Button) findViewById(R.id.bt_Tests);
        bt_mission = (Button) findViewById(R.id.BT_Mission);
        relativeLayout = (RelativeLayout) findViewById(R.id.rl);

        bt_info.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View view){
                layoutInflater = (LayoutInflater) getApplicationContext().getSystemService(LAYOUT_INFLATER_SERVICE);
                ViewGroup container = (ViewGroup) layoutInflater.inflate(R.layout.popup,null);

                popupWindow = new PopupWindow(container, ActionBar.LayoutParams.WRAP_CONTENT, ActionBar.LayoutParams.WRAP_CONTENT,true);
                if(Build.VERSION.SDK_INT>=21){
                    popupWindow.setElevation(5.0f);
                }
                popupWindow.showAtLocation(relativeLayout, Gravity.CENTER,0,0);

                Button closeButton = (Button) container.findViewById(R.id.bt_ClosePopUp);
                closeButton.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        // Dismiss the popup window
                        popupWindow.dismiss();
                    }
                });


            }

        });

        bt_settings.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View view){
                Intent intentsettings = new Intent(MainActivity.this, SettingsActivity.class);
                startActivity(intentsettings);

            }

        });

        bt_tests.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View view){
                Intent intenttests = new Intent(MainActivity.this, TestsActivity.class);
                startActivity(intenttests);
                //MainActivity.this.finish();
                finish();
            }

        });

        bt_mission.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View view){
                Intent intentmission = new Intent(MainActivity.this, MissionActivity.class);
                startActivity(intentmission);
                //MainActivity.this.finish();
                finish();
            }

        });



    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.lb_Title);
    //tv.setText(stringFromJNI());
    }

    private void getOverflowMenu() {

        try {
            ViewConfiguration config = ViewConfiguration.get(this);
            Field menuKeyField = ViewConfiguration.class.getDeclaredField("sHasPermanentMenuKey");
            if(menuKeyField != null) {
                menuKeyField.setAccessible(true);
                menuKeyField.setBoolean(config, false);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onBackPressed() {
        new AlertDialog.Builder(this)
                .setMessage("Are you sure you want to exit?")
                .setCancelable(false)
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        //MainActivity.this.finish();
                        finish();
                    }
                })
                .setNegativeButton("No", null)
                .show();
    }

}
