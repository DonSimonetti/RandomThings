//
// Created by matteo on 29/08/18.
//
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include "GameMode.h"
#include "pwnutils.h"
#include "Map.h"
#include "MapsList.h"
#include "Colors.h"

using sampgdk::logprintf;
using std::string;

unsigned int buildNumber=BUILD_REVISION;

MapsList * mapsList;

void onGameModeInit()
{
    AddServerRule("GM Build Version","Gm build version");

    SetGameModeText("Freeroam");
    SetServerLanguage("English/Italian");

    loadMaps();

    //PlayerClasses
    for(int s = 0; s < 299; s++)
    {
        if(isValidSkin(s)) AddPlayerClass(s, 493.0551,-2667.4963,58.9676, 180, -1, -1, -1, -1, -1, -1);
    }
}

void onGameModeExit()
{

}

bool onPlayerConnect(int playerid)
{
    string msg(GetPlayerNameStr(playerid));
    msg.append("{FFFFFF} joined the server!");
    SendClientMessageToAll(COLOR_CONNECTED,msg.c_str());
    PlayerPlaySound(playerid,1097,0.0,0.0,0.0);
    SetPlayerSkillLevel(playerid,WEAPONSKILL_PISTOL,40);
    return false;
}

bool onPlayerRequestClass(int playerid,int classid)
{
    SetPlayerPos(playerid,493.0551,-2667.4963,58.9676);
    SetPlayerFacingAngle(playerid,180);
    SetPlayerCameraPos(playerid, 491.3301, -2673.4231, 61.4380);
    SetPlayerCameraLookAt(playerid, 493.0551,-2667.4963,58.9676,CAMERA_CUT);
    return true;
}

bool onPlayerSpawn(int playerid)
{
    PlayerPlaySound(playerid,1098,0.0,0.0,0.0);
    return false;
}

bool onPlayerDisconnect(int playerid, int reason)
{
    if(!reason)
    {
        string msg(GetPlayerNameStr(playerid));
        SendClientMessageToAll(COLOR_CRASH,msg.append("{FFFFFF} left the server. (Timeout/Crash)").c_str());
    }
    SendDeathMessage(-1,playerid,201);
    return true;
}



bool onPlayerCommandText(int playerid, const string & cmdtext)
{
    string cmd(cmdtext);
    cmd.erase(0,1);//erase "/" char
    if(cmd=="/cmd")
    {
        SendClientMessage(playerid,-1,"Server under construction. Ask admin");
        return true;
    }
    if(cmd=="/kill")
    {
        SetPlayerHealth(playerid,0);
        return true;
    }
    return false;
}

void loadMaps()
{
    mapsList=new MapsList;

    Map * spawnMap=new Map("spawnpoint.pwn",400.0);//Only supports CreateObject
    mapsList->vector.push_back(spawnMap);

    Map * usabaseMap=new Map("baseusa.pwn",400.0);
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
