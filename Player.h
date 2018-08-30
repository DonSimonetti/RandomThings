//
// Created by matteo on 28/08/18.
//

#ifndef RANDOMTHINGS_PLAYER_H
#define RANDOMTHINGS_PLAYER_H

#include <string>
#include "sampgdk.h"

class Player {

public:

    Player(int playerid);

    const std::string GetName() const;

    void SetName(std::string newName);

protected:

    int clientId;
};


#endif //RANDOMTHINGS_PLAYER_H
