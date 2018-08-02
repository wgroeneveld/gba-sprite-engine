//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memmap.h>
#include <engine/palette_manager.h>
#include "text_stream.h"

#include <memory>

TextStream* TextStream::inst;

void TextStream::clear() {
    currRow = 0;
    currCol = 0;
    clearMap();
}

TextStream::TextStream() : Background(0, text_data, sizeof(text_data), nullptr, TILE_WIDTH * TILE_WIDTH), currCol(0), currRow(0) {
    useMapScreenBlock(24);
    this->palette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    persist();
    clearMap();
}

void log_text(const char* text) {
    TextStream::instance().clear();
    TextStream::instance() << text;
}

void consoleLog_func(const char* fileName, const int lineNr, const char* fnName, const char* msg) {
    TextStream::instance().clear();
    char lineNrBuf[10];
    itoa(lineNr, lineNrBuf, 10);

    TextStream::instance() <<
                           (std::string("DEBUG: ") +
                            std::string(fileName) +
                            std::string(":") +
                            std::string(fnName) +
                            std::string("@") +
                            std::string(lineNrBuf) +
                            std::string(" -- ") +
                            std::string(msg))
                            .c_str();
}

TextStream& TextStream::instance() {
    if(!inst) {
        inst = new TextStream();
    }
    return *inst;
}

// thank you Ian
// http://cs.umw.edu/~finlayson/class/spring18/cpsc305/
void TextStream::setText(const char* text, int row, int col) {
    int index = row * TILE_WIDTH + col;

    volatile auto ptr = &se_mem[screenBlockIndex][0];
    while (*text) {
        ptr[index] = *text - CHAR_OFFSET_INDEX;

        index++;
        text++;
    }

}

TextStream& TextStream::operator<<(const int s) {
    return *this << std::to_string(s).c_str();
}

TextStream& TextStream::operator<<(const u32 s) {
    return *this << std::to_string(s).c_str();
}

TextStream& TextStream::operator<<(const bool s) {
    return *this << (s ? "TRUE" : "FALSE");
}

TextStream& TextStream::operator<<(const char * s) {
    setText(s, currRow, currCol);
    currRow++;
    return *this;
}

void TextStream::setTextColor(COLOR color) {
    palette.get()->change(PALETTE_TEXT_BANK, PALETTE_COLOR_INDEX, color);
}

void TextStream::persist() {
    Background::persist();
    // WARNING: stream hijacks last bg palette bank, last index, no matter what.
    setTextColor(PaletteManager::color(31, 31, 31));
}
