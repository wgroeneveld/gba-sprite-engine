//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_TEXT_STREAM_H
#define GBA_SPRITE_ENGINE_TEXT_STREAM_H

#include "background.h"
#include "text.h"

#include <string>

#define CHAR_OFFSET_INDEX 32
#define TILE_WIDTH 32

#define failure(__mess) (consoleLog_func(__FILE__, __LINE__, __PRETTY_FUNCTION__, #__mess))
void log_text(const char* text);
void consoleLog_func(const char* fileName, const int lineNr, const char* fnName, const char* msg);

class TextStream : public Background {
private:
    int currRow, currCol;

    static TextStream* inst;
    TextStream();
    TextStream(TextStream& other) = delete;
    TextStream(TextStream&& other) = delete;

public:
    void clear();
    void setText(const char* text, int row, int col);
    static TextStream& instance();

    TextStream& operator << (const char* s);
    TextStream& operator << (const int s);
    TextStream& operator << (const u32 s);
    TextStream& operator << (const bool s);
};


#endif //GBA_SPRITE_ENGINE_TEXT_STREAM_H
