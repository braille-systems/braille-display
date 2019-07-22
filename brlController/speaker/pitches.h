#ifndef BRLCONTROLLER_PITCHES_H
#define BRLCONTROLLER_PITCHES_H

//TODO: optimize all
namespace note{
    enum note_t{
        none = -1,
        b4 = 494,
    };
}
    //джойстик
    #define NOTE_B4  494
    #define NOTE_C4  262
    #define NOTE_A4  440
    #define NOTE_E4  330

    //кнопка джойстика
    #define NOTE_D4  293

    //клавиатура
    #define NOTE_C3  131
    #define NOTE_D3  148
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_G3  196
    #define NOTE_A3  207


#endif //BRLCONTROLLER_PITCHES_H
