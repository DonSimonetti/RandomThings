#include <cstdio>
#include <cstring>
#include <string>
//#include <map>

#include "sampgdk.h"
#include "GameMode.h"

using sampgdk::logprintf;
using std::string;

//std::map<int, Player*> players;

void SAMPGDK_CALL PrintTickCountTimer(int timerid, void *params) {
  sampgdk::logprintf("Tick count: %d", GetTickCount());
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
    return onGameModeInit();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
    return onPlayerConnect(playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid)
{
    SetPlayerPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
    SetPlayerCameraPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
    SetPlayerCameraLookAt(playerid, 1958.3783f, 1343.1572f, 15.3746f, CAMERA_CUT);
    return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickMap(int playerid, float fX,float fY,float fZ)
{
    SetPlayerPos(playerid,fX,fY,fZ);
    return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
  return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
    return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
  sampgdk::ProcessTick();
}
