package com.example.app_nfc;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "devhome.smartdoorApp";

    private TextView textStatus, textLuminosity;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus =     findViewById(R.id.textStatus);                      // Acessa os componentes da tela
        textLuminosity = findViewById(R.id.textLuminosity);
    }

    // Executado ao clicar no botão "SET" do Led.
    public void updateLed(View view) {
        // initiate a Switch
        Switch simpleSwitch = (Switch) findViewById(R.id.simpleSwitch);

        // check current state of a Switch (true or false).
        Boolean switchState = simpleSwitch.isChecked();
        int newLed = (switchState) ? 1 : 0;
        //int newLed = Integer.parseInt(switchState.toString());     // Executa o método getLed via IPC
        if(switchState)
            textLuminosity.setText(String.valueOf("Aberto"));
        else textLuminosity.setText(String.valueOf("Fechado"));
    }
}