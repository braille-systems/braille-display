#ifndef BRLCONTROLLER_MAIN_H
#define BRLCONTROLLER_MAIN_H

#include"device.h"

device d;

void setup() {
#ifndef DEBUG_MODE
    //bind stdout and stdin to serial port
    Serial.begin(9600);
#endif
}

void loop() {
    bool serOn = d.ser.isConnected();
    if(serOn) d.processSerInput();
    keysRefreshRes keysRes = d.ctrl.refresh();
    d.sound.setMode(keysRes.soundMode);
    if(keysRes.toSpeaker != note::none && d.sound.on())
        d.sound.play(keysRes.toSpeaker);
    if(keysRes.toSerial.length() > 0){
        if(serOn) d.ser.send(keysRes.toSerial);
        else d.brlDisp.setText(keysRes.toSerial);
    }
    if(d.brlDisp.isWorking()){
        dispRefreshRes dispRes = d.brlDisp.refresh();
        if(serOn && dispRes.toSerial.length() > 0)
            d.ser.send(dispRes.toSerial);
    }
}

#endif //BRLCONTROLLER_MAIN_H
