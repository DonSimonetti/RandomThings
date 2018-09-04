//
// Created by matteo on 30/08/18.
//

#include <fstream>
#include "Map.h"
#include "sampgdk.h"
#include "pwnutils.h"

using sampgdk::logprintf;

Map::Map(std::string file, float _drwDistance) : name(file), drawDistance(_drwDistance)
{
    loadMap();
}

Map::~Map()
{
    for(std::vector<int>::iterator item = objects.begin(); item!=objects.end(); item++)
    {
        if(IsValidObject(*item))
            DestroyObject(*item);
    }
}

void Map::loadMap()
{
    string mapdir(getCurrentDirectory()+"/scriptfiles/Maps/"+name);
    if(fileExists(mapdir))
    {
        logprintf("[RandomThings] Loading Map \" %s \" ...",name.c_str());

        std::ifstream mapfile;
        mapfile.open(mapdir.c_str());
        if(mapfile.is_open())
        {
            string line;
            int objNumber=0;
            while(getline(mapfile,line))
            {
                if(line.find("CreateObject(")!=std::string::npos)
                {
                    loadStandardObject(line,objNumber);
                    objNumber++;
                }
                else if(line.find("CreateDynamicObject(")!=std::string::npos)
                {
                    //loadDynamicObject(line, objNumber);
                    objNumber++;
                }
            }
            mapfile.close();

            logprintf("[RandomThings] Loading Completed!");
        }
    }
    else
        logprintf("[RandomThings] Requested loading Map \" %s \" but file doesn't exist. Skipped.",mapdir.c_str());
}

void Map::loadStandardObject(string line, int index)
{
    line.erase(0, line.find("CreateObject(") + string("CreateObject(").length());
    line.erase(line.find_last_of(")"), line.length());

    int modelid;
    float posX, posY, posZ, rotX, rotY, rotZ;
    int succCode = sscanf(line.c_str(), "%d,%f,%f,%f,%f,%f,%f", &modelid, &posX, &posY, &posZ, &rotX, &rotY, &rotZ);

    if (succCode == 7)
    {
        int obj;
        AMX_NATIVE native=sampgdk_FindNative("CreateDynamicObject");
        if(native!=NULL)
        {
            obj=sampgdk_InvokeNative(native,"dffffffdddffdd",modelid,posX,posY,posZ,rotX,rotY,rotZ,-1,0,-1,drawDistance,drawDistance,-1,0);
        }
        else
        {
            obj = CreateObject(modelid, posX, posY, posZ, rotX, rotY, rotZ, drawDistance);
        }
        objects.push_back(obj);
    }
    else
        logprintf("Error: Object %d has wrong format",index);
}

void Map::loadDynamicObject(std::string line, int index)
{
    /*line.erase(0, line.find("CreateDynamicObject(") + string("CreateDynamicObject(").length());
    line.erase(line.find_last_of(")"), line.length());

    unsigned int modelid;
    float posX, posY, posZ, rotX, rotY, rotZ;
    int succCode = sscanf(line.c_str(), "%d,%f,%f,%f,%f,%f,%f", &modelid, &posX, &posY, &posZ, &rotX, &rotY, &rotZ);

    if (succCode == 7)
    {
        requiredStreamer=true;
        //int obj = CreateObject(modelid, posX, posY, posZ, rotX, rotY, rotZ, drawDistance);
        AMX_NATIVE native=sampgdk_FindNative("CreateDynamicObject");
        if(native!=NULL)
        {
            int obj=sampgdk_InvokeNative(native,"dffffff")
            objects.push_back(obj);
        } else
            logprintf("  Unable to load object! Required streamer");
    }
    else
        logprintf("  Error: Object %d has wrong format",index);*/
}