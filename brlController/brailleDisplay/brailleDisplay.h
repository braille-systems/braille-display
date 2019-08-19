#ifndef BRLCONTROLLER_BRAILLEDISPLAY_H
#define BRLCONTROLLER_BRAILLEDISPLAY_H

#ifdef DEBUG_MODE
	#include<string>
	#ifndef String
			#define String std::string
    #endif //String
#endif //DEBUG_MODE

struct dispRefreshRes{
    String toSerial;
    bool isWorking;
};

class brailleDisplay{
public:
    void setText(String txt);
    dispRefreshRes refresh();
    bool isWorking(){return false; /*TODO: implement*/}
};

void brailleDisplay::setText(String txt){/*TODO: implement*/}
dispRefreshRes brailleDisplay::refresh(){
    //TODO: implement with single-cell display
    /**@usage call as frequently as possible for smooth motor movements.
     * Normally delay inside this function <= 0.1 sec*/
    dispRefreshRes res;
    res.isWorking = false;
    return res;
}

#endif //BRLCONTROLLER_BRAILLEDISPLAY_H
