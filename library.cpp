#include <cstdio>
#include <cstring>
#include <string>

#include "sampgdk.h"
#include "mainscript.h"

using sampgdk::logprintf;

void SAMPGDK_CALL PrintTickCountTimer(int timerid, void *params) {
  sampgdk::logprintf("Tick count: %d", GetTickCount());
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
    SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the HelloWorld server!");
    return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid)
{
  SetPlayerPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
  SetPlayerCameraPos(playerid, 1958.3783f, 1343.1572f, 15.3746f);
  SetPlayerCameraLookAt(playerid, 1958.3783f, 1343.1572f, 15.3746f, CAMERA_CUT);
  return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext)
{
  const std::string command(cmdtext);
  return onPlayerCommandText(playerid,command);
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
  return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
  return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
  sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
  sampgdk::ProcessTick();
}
