//
// Created by matteo on 25/08/18.
//

#include "pwnutils.h"
#include "sampgdk.h"

void SetServerLanguage(std::string lang)
{
    std::string cmd("language "+lang);
    SendRconCommand(cmd.c_str());
}
