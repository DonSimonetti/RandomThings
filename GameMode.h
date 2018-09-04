//
// Created by matteo on 29/08/18.
//

#ifndef RANDOMTHINGS_GAMEMODE_H
#define RANDOMTHINGS_GAMEMODE_H

#include <string>
#include "sampgdk.h"

using std::string;

//Callbacks
void onGameModeInit();
void onGameModeExit();
bool onPlayerConnect(int playerid);
bool onPlayerRequestClass(int playerid,int classid);
bool onPlayerDisconnect(int playerid, int reason);
bool onPlayerSpawn(int playerid);
bool onPlayerCommandText(int playerid, const string & cmdtext);
//functions
void loadMaps();
bool isValidSkin(int skinid);


#endif //RANDOMTHINGS_GAMEMODE_H
