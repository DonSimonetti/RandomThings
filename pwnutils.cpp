//
// Created by matteo on 25/08/18.
//

#include <unistd.h>
#include <fstream>
#include <memory>
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
    std::unique_ptr<char> buf(new char[64]);
    getcwd(buf.get(),64);
    string dir(buf.get());
    return dir;
}

bool fileExists(const string & file)
{
    std::ifstream infile(file.c_str());
    return infile.good();
}