//
// Created by matteo on 29/08/18.
//
#include <unistd.h>
#include <fstream>
#include "GameMode.h"
#include "pwnutils.h"
#include "Map.h"
#include "MapsList.h"

using sampgdk::logprintf;
using std::string;

unsigned int buildNumber=BUILD_REVISION;

MapsList * mapsList;

bool onGameModeInit()
{
    sampgdk_InvokeNative(sampgdk_FindNative("AddServerRule"),"ssd","GM build",string(""+buildNumber).c_str(),3);

    SetGameModeText("RandomThings++");
    SetServerLanguage("English/Italian");
    loadMaps();

    //Classes
    for(int s = 0; s < 299; s++)
    {
        if(isValidSkin(s)) AddPlayerClass(s, 493.0551,-2667.4963,58.9676, 180, -1, -1, -1, -1, -1, -1);
    }
    return true;
}

bool onGameModeExit()
{
    return true;
}

bool onPlayerConnect(int playerid)
{
    string msg(GetPlayerNameStr(playerid));
    msg.append(" connected to the server");
    SendClientMessageToAll(-1,msg.c_str());
    return true;
}

void loadMaps()
{
    mapsList=new MapsList;

    Map * spawnMap=new Map("spawnpoint.pwn",1000.0);//Only supports CreateObject
    mapsList->vector.push_back(spawnMap);

    Map * usabaseMap=new Map("baseusa.pwn",1000.0);
    mapsList->vector.push_back(usabaseMap);
}

bool isValidSkin(int skinid)
{
    int badSkins[1] = {74};
    for(int i = 0; i < 1; i++)
    {
        if(skinid == badSkins[i]) return false;
    }
    return true;
}
