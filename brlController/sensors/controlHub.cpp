#include"controlHub.h"

keysRefreshRes controlHub::refresh(){
    /*TODO: implement*/
    /**@usage call as frequently as possible to catch all user's input.
     * Normally there is no delay in this function*/
    keysRefreshRes res;
    res.toSerial = "";
    res.toSpeaker = note::none;
    res.soundMode = true; //sound on
    return res;
}
