//
// Created by matteo on 30/08/18.
//

#ifndef RANDOMTHINGS_MAP_H
#define RANDOMTHINGS_MAP_H

#include <string>
#include <vector>

class Map {

public:
    Map(std::string file, float _drwDistance);
    ~Map();

private:
    std::string name;
    float drawDistance;
    std::vector<int> objects;
    bool requiredStreamer=false;

    void loadMap();
    void loadStandardObject(std::string line, int index);
    void loadDynamicObject(std::string line, int index);
};


#endif //RANDOMTHINGS_MAP_H
