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
void AddServerRule(const std::string & name, const string & value, int flag=3);

#endif //TESTGDK_PWNUTILS_H
