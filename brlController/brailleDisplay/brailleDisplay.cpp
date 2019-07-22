#include "brailleDisplay.h"

void brailleDisplay::setText(std::string txt){/*TODO: implement*/}
dispRefreshRes brailleDisplay::refresh(){
    //TODO: implement with single-cell display
    /**@usage call as frequently as possible for smooth motor movements.
     * Normally delay inside this function <= 0.1 sec*/
    dispRefreshRes res;
    res.isWorking = false;
    return res;
}
