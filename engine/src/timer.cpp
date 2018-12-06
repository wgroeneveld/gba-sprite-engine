//
// Created by Wouter Groeneveld on 06/12/18.
//

#include <libgba-sprite-engine/timer.h>
#include <sstream>

void Timer::onvblank() {
    if(!active) return;

    // each VBlank occurs every 280806 cycles (CYCLES_PER_BLANK), each cycle is 59.59ns
    // So, each VBlank occurs every 16.73322954 miliseconds or 16733.22954 microseconds
    // So, each second is 59,76132686219041 vblanks.
    // to avoid any big rounding errors, divisions and modulos, estimate!
    msecs += 16;
    microsecs += 733;
    if(microsecs >= 1000) {
        msecs++;
        microsecs -= 1000;
    }

    if(msecs >= 1000) {
        secs++;
        msecs -= 1000;
    }
    if(secs >= 60) {
        minutes++;
        secs -= 60;
    }
    if(minutes >= 60) {
        hours++;
        minutes -= 60;
    }
}

std::string Timer::to_string() {
    std::ostringstream stringStream;
    stringStream << *this;
    return stringStream.str();
}

std::ostream& operator<<(std::ostream &os, Timer &timer) {
    os << timer.hours << "h:" << timer.minutes << "m:" << timer.secs << "s:" << timer.msecs;
    return os;
}

void Timer::reset() {
    microsecs = msecs = secs = minutes = hours = 0;
}

void Timer::start() {
    active = true;
}

void Timer::stop() {
    active = false;
}