#ifndef __REGION_H_
#define __REGION_H_

#include "Resource.h"
#include <string>
#include <map>
#include "Map.h"

class Region : public Resource
{   std::string regionName;
    std::map<std::string, Map*> areas;

    public:
       Region(char* path);
       std::string getName();
       Map* getStartingMap();
       Map* getMap(std::string name);
       size_t getSize();
       ~Region();
};

#endif
