//
// Created by matteo on 25/08/18.
//

#include "mainscript.h"
#include "sampgdk.h"
#include "pwnutils.h"

using sampgdk::logprintf;

bool onPlayerCommandText(int playerid, const std::string & cmdtext)
{
    SendClientMessage(playerid,-1,cmdtext.c_str());
    if(cmdtext=="/hello")
    {
        SendClientMessage(playerid,-1,"the gm is working!");
        return true;
    }
    return false;
}