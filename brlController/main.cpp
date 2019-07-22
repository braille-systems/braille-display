#include"device.h"

device d;

void setup() {
}

void loop() {
    bool serOn = d.ser.isConnected();
    if(serOn) d.processSerInput();
    keysRefreshRes keysRes = d.ctrl.refresh();
    d.sound.setMode(keysRes.soundMode);
    if(keysRes.toSpeaker != note::none && d.sound.on())
        d.sound.play(keysRes.toSpeaker);
    if(!keysRes.toSerial.empty()){
        if(serOn) d.ser.send(keysRes.toSerial);
        else d.brlDisp.setText(keysRes.toSerial);
    }
    if(d.brlDisp.isWorking()){
        dispRefreshRes dispRes = d.brlDisp.refresh();
        if(serOn && !dispRes.toSerial.empty())
            d.ser.send(dispRes.toSerial);
    }
}

int main(void){
    setup();
    while(true) loop();
}

