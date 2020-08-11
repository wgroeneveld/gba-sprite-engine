//
// Created by michi on 10/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H


class Minigame {
protected:
    int score;
    int posX;
    int posY;
    int posBoxX;
    int posBoxY;
    bool gehaald;
    int snelheid;
public:
    Minigame();
    int getScore();
    int getPosX();
    int getPosY();
    int getPosBoxX();
    int getPosBoxY();
    bool getGehaald();
    void makePicture();
    virtual void berekenGehaald() = 0;
    virtual void beweeg() = 0;
    virtual void berekenScore() = 0;

    //void moveBoxRight();
    //void moveBoxLeft();
    //void moveBoxUp();
    //void moveBoxDown();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H
