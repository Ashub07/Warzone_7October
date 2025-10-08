#include "GameEngine.h"
#include <iostream>

int main() {
    GameEngine engine;

    engine.processCommand("loadmap");
    engine.processCommand("validatemap");
    engine.processCommand("addplayer");
    engine.processCommand("assigncountries");
    engine.processCommand("issueorder");
    engine.processCommand("endissueorders");
    engine.processCommand("endexecorders");
    engine.processCommand("win");
    engine.processCommand("end");

    return 0;
}
