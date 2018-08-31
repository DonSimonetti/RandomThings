//
// Created by matteo on 29/08/18.
//

#ifndef RANDOMTHINGS_GAMEMODE_H
#define RANDOMTHINGS_GAMEMODE_H

#include <string>
#include "sampgdk.h"

//Callbacks
void onGameModeInit();
bool onGameModeExit();
bool onPlayerConnect(int playerid);
//functions
void loadMaps();
bool isValidSkin(int skinid);


#endif //RANDOMTHINGS_GAMEMODE_H
