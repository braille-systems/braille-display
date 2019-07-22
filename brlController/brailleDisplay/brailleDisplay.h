#ifndef BRLCONTROLLER_BRAILLEDISPLAY_H
#define BRLCONTROLLER_BRAILLEDISPLAY_H

#include<string>

struct dispRefreshRes{
    std::string toSerial;
    bool isWorking;
};

class brailleDisplay{
public:
    void setText(std::string txt);
    dispRefreshRes refresh();
    bool isWorking(){return false; /*TODO: implement*/}
};
#endif //BRLCONTROLLER_BRAILLEDISPLAY_H
