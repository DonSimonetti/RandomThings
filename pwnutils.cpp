//
// Created by matteo on 25/08/18.
//

#include <unistd.h>
#include <fstream>
#include "pwnutils.h"
#include "sampgdk.h"

using std::string;

void SetServerLanguage(std::string lang)
{
    std::string cmd("language "+lang);
    SendRconCommand(cmd.c_str());
}

const std::string GetPlayerNameStr(int playerid)
{
    char * nameptr=new char[MAX_PLAYER_NAME];
    GetPlayerName(playerid,nameptr,MAX_PLAYER_NAME);
    std::string name(nameptr);
    delete [] nameptr;
    return name;
}

string getCurrentDirectory()
{
    char * buf=new char[32];
    getcwd(buf,32);
    string dir(buf);
    delete [] buf;
    return dir;
}

bool fileExists(const string & file)
{
    std::ifstream infile(file.c_str());
    return infile.good();
}