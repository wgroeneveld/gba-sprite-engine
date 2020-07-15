//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H


class Minigame2 {
private:
    int score;
    int positieX;
    bool rechts;
public:
    Minigame2();
    int getScore();
    void MakePicture();
    void GameOver();
    void beweeg();
    int getPositieX();
    void wisselRichting();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H
