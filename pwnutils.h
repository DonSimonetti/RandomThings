//
// Created by matteo on 25/08/18.
//

#ifndef TESTGDK_PWNUTILS_H
#define TESTGDK_PWNUTILS_H

#include <string>

using std::string;

void SetServerLanguage(std::string lang);
const std::string GetPlayerNameStr(int playerid);
string getCurrentDirectory();
bool fileExists(const string & file);

#endif //TESTGDK_PWNUTILS_H
