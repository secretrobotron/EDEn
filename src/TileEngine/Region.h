/*
 *  This file is covered by the Ruby license. See LICENSE.txt for more details.
 *
 *  Copyright (C) 2007-2012 Noam Chitayat. All rights reserved.
 */

#ifndef REGION_H
#define REGION_H

#include "Resource.h"
#include <string>
#include <map>

class Map;

/**
 * A Region is a large spatial area that the player can walk around within.
 * Technically speaking, it's a set of Map instances that are tied together
 * as a cohesive unit that is loaded all at once to allow seamless transitioning
 * between locations in the same area, such as different houses in a town,
 * or different levels of a single dungeon.
 * A Region contains a series of Maps keyed by their names. 
 * The first map loaded from file becomes the starting map, and the player
 * character begins there when entering a region unless otherwise specified.
 *
 * @author Noam Chitayat
 */
class Region : public Resource
{
   /** The name of the region. */
   std::string regionName;

   /** The list of maps in this region, keyed by map names. */
   std::map<std::string, Map*> areas;

   /**
    * Loads this region from the specified EDR file.
    *
    * @param path The path to the file containing the region and its maps.
    */
   virtual void load(const std::string& path);

   public:
      /**
       * Constructor.
       */
      Region(const ResourceKey& name);

      /** @return the name of the region. */
      std::string getName();

      /** @return the starting map (first map loaded) for this Region. */
      Map* getStartingMap();

      /**
       * @param name The name of the Map to retrieve.
       *
       * @return the Map with the specified name.
       */
      Map* getMap(const std::string& name);

      /**
       * Implementation of method in Resource class.
       *
       * @return The size of the region resource in memory.
       */
      size_t getSize();

      /**
       * Destructor.
       */
      ~Region();
};

#endif
