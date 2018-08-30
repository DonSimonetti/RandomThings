//
// Created by matteo on 30/08/18.
//

#ifndef RANDOMTHINGS_MAPSLIST_H
#define RANDOMTHINGS_MAPSLIST_H

#include <vector>

#include "Map.h"

class MapsList {
public:

    MapsList()= default;
    /*static MapsList* CreateMapsList();
    static MapsList* GetMainList() {
        return mainList;
    }
*/


    std::vector<Map*> vector;

private:


    //static MapsList * mainList;



};


#endif //RANDOMTHINGS_MAPSLIST_H
