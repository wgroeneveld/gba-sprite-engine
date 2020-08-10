//
// Created by michi on 10/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H


class Minigame {
private:

protected:
    int score;
    int posX;
    int posY;
    int minScore;
    bool gehaald;
    int snelheid;
public:
    Minigame();
    int getScore();
    int getPosX();
    int getPosY();
    bool getGehaald();
    void makePicture();
    void berekenGehaald();
    virtual void beweeg() = 0;
    virtual void berekenScore() = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME_H
