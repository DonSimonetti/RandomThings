//
// Created by matteo on 28/08/18.
//

#include "Player.h"

Player::Player(int playerid) : clientId(playerid) {}

const std::string Player::GetName() const
{
    char * _name=new char[MAX_PLAYER_NAME];
    GetPlayerName(clientId,_name,MAX_PLAYER_NAME);
    std::string ret(_name);
    delete [] _name;
    return ret;
}

void Player::SetName(std::string newName)
{
    SetPlayerName(clientId,newName.c_str());
}