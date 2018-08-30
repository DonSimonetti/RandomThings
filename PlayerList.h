//
// Created by matteo on 28/08/18.
//

#ifndef RANDOMTHINGS_PLAYERLIST_H
#define RANDOMTHINGS_PLAYERLIST_H

#include <map>
#include "Player.h"

class PlayerList {

public:
    PlayerList();

    std::map<int , Player*> players;
};


#endif //RANDOMTHINGS_PLAYERLIST_H
