package com.example.exploprotobuf;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TCPClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        client = new TCPClient(this);
    }

    public void onClickMessageArretUrgence(View view){
        client.sendMessage(0x01, 0xFF);
    }
    public void onClickMessageStopMarco(View view){
        client.sendMessage(0x03, 0x00);
    }
    public void onClickMessageDeplacementManuel(View view){
        client.sendMessage(0x05, 0xFF);
    }
    public void onClickMessageSetExploAlgo(View view){
        client.sendMessage(0x07, 0x0F);
    }


    public void onClickConnection(View view) {
        Log.i("Conenction", "Click avant");
        client.connect("172.21.10.248");
        Log.i("Conenction", "Click après");

    }


    public void updateTextView(int id, int data) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TextView textView = findViewById(R.id.batteryTextView);
                textView.setText("ID: " + id + ", Data: " + data);
            }
        });
    }


}