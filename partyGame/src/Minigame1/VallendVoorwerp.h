//
// Created by michi on 28/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_VALLENDVOORWERP_H
#define GBA_SPRITE_ENGINE_PROJECT_VALLENDVOORWERP_H


class VallendVoorwerp {
private:
    int positieX;
    int positieY;
    bool bom;
public:
    VallendVoorwerp(bool isBom);
    int getPositieX();
    int getPositieY();
    bool isEenBom();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_VALLENDVOORWERP_H
