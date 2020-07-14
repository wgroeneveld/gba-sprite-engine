//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#define GBA_SPRITE_ENGINE_PROJECT_SPELER_H


class Speler {
private:
    int score{};

public:
    Speler();
    int getScore();
    void setScore(int nieuweScore);


};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
