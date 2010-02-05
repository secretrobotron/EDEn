#include "TileEngine.h"
#include "ScriptEngine.h"
#include "NPC.h"
#include "PlayerCharacter.h"
#include "Scheduler.h"
#include "Container.h"
#include "GraphicsUtil.h"
#include "ResourceLoader.h"
#include "Region.h"
#include "Map.h"
#include "DialogueController.h"
#include "OpenGLTTF.h"

#include "DebugUtils.h"
const int debugFlag = DEBUG_TILE_ENG;

const int TileEngine::TILE_SIZE = 32;

TileEngine::TileEngine(std::string chapterName)
                                   : currMap(NULL), xMapOffset(0), yMapOffset(0)
{
   player = new PlayerCharacter(ResourceLoader::getSpritesheet("crono"), 320, 320);
   scheduler = new Scheduler();
   scriptEngine = new ScriptEngine(this, scheduler);
   dialogue = new DialogueController(top, scriptEngine);
   time = SDL_GetTicks();
   scheduler->start(dialogue);
   scriptEngine->runChapterScript(chapterName);
}

std::string TileEngine::getMapName()
{
   return currMap->getName();
}

void TileEngine::dialogueNarrate(const char* narration, Task* task)
{
   dialogue->narrate(narration, task);
}

void TileEngine::dialogueSay(const char* speech, Task* task)
{
   dialogue->say(speech, task);
}

bool TileEngine::setRegion(std::string regionName, std::string mapName)
{
   DEBUG("Loading region: %s", regionName.c_str());
   currRegion = ResourceLoader::getRegion(regionName);
   DEBUG("Loaded region: %s", currRegion->getName().c_str());

   setMap(mapName);

   DEBUG("Running map script: %s/%s", regionName.c_str(), currMap->getName().c_str());
   return true;
}

void TileEngine::setMap(std::string mapName)
{
   DEBUG("Setting map...");
   if(!mapName.empty())
   {
      // If a map name was supplied, then we set this map and run its script
      currMap = currRegion->getMap(mapName);
   }
   else
   {
      // Otherwise, we use the region's default starting map
      currMap = currRegion->getStartingMap();
      mapName = currMap->getName();
   }

   DEBUG("Map set to: %s", mapName.c_str());

   recalculateMapOffsets();
}

void TileEngine::recalculateMapOffsets()
{
   const int mapPixelWidth = currMap->getWidth() * TILE_SIZE;
   const int mapPixelHeight = currMap->getHeight() * TILE_SIZE;

   xMapOffset = mapPixelWidth < GraphicsUtil::width ? 
              (GraphicsUtil::width - mapPixelWidth) >> 1 : 0;

   yMapOffset = mapPixelHeight < GraphicsUtil::height ?
              (GraphicsUtil::height - mapPixelHeight) >> 1 : 0;
}

void TileEngine::addNPC(std::string npcName, std::string spritesheetName, int x, int y)
{
   Spritesheet* sheet = ResourceLoader::getSpritesheet(spritesheetName);
   npcList[npcName] = new NPC(scriptEngine, scheduler, sheet,
                           currRegion->getName(), currMap->getName(), npcName,
                           x * TILE_SIZE, y * TILE_SIZE);
}

void TileEngine::moveNPC(std::string npcName, int x, int y)
{
   NPC* npcToMove = npcList[npcName];
   npcToMove->move(x, y);
}

void TileEngine::setNPCSprite(std::string npcName, std::string frameName)
{
   NPC* npcToChange = npcList[npcName];
   npcToChange->setFrame(frameName);
}

void TileEngine::setNPCAnimation(std::string npcName, std::string animationName)
{
   NPC* npcToChange = npcList[npcName];
   npcToChange->setAnimation(animationName);
}

void TileEngine::changeNPCSpritesheet(std::string npcName, std::string spritesheetName)
{
   Spritesheet* sheet = ResourceLoader::getSpritesheet(spritesheetName);
   NPC* npcToChange = npcList[npcName];
   npcToChange->setSpritesheet(sheet);
}

void TileEngine::stepNPCs(long timePassed)
{
   std::map<std::string, NPC*>::iterator iter;

   for(iter = npcList.begin(); iter != npcList.end(); ++iter)
   {
      NPC* currNPC = iter->second;
      currNPC->step(timePassed);
   }
}

void TileEngine::drawNPCs()
{
   std::map<std::string, NPC*>::iterator iter;

   for(iter = npcList.begin(); iter != npcList.end(); ++iter)
   {
      NPC* currNPC = iter->second;
      currNPC->draw();
   }
}

void TileEngine::draw()
{
   GraphicsUtil::getInstance()->setOffset(xMapOffset, yMapOffset);
      // Draw the map and NPCs against an offset (to center all the map elements)
      if(currMap != NULL)
      {
         currMap->draw();
      }
      else
      {
         GraphicsUtil::getInstance()->clearBuffer();
      }
   
      drawNPCs();
      player->draw();
   GraphicsUtil::getInstance()->resetOffset();

   GameState::draw();
   GraphicsUtil::getInstance()->flipScreen();
}

bool TileEngine::step()
{
   long prevTime = time;
   time = SDL_GetTicks();

   long timePassed = time - prevTime;
   if(timePassed > 32)
   {
      timePassed = 32;
   }

   GameState::step();

   bool done = false;
   scheduler->runThreads(timePassed);

   SDL_Event event;

   /* Check for events */
   while(SDL_PollEvent(&event))
   {
      switch (event.type)
      {
         case SDL_USEREVENT:
         {
            case SDL_KEYDOWN:
            {
               switch(event.key.keysym.sym)
               {
                  case SDLK_SPACE:
                  {
                     dialogue->setFastModeEnabled(true);
                     dialogue->nextLine();
                     break;
                  }
                  case SDLK_ESCAPE:
                  {
                     done = true;
                     break;
                  }
                  default:
                  {
                  }
               }
               break;
            }
            case SDL_KEYUP:
            {
               switch(event.key.keysym.sym)
               {
                  case SDLK_SPACE:
                  {
                     dialogue->setFastModeEnabled(false);
                     break;
                  }
                  default:
                  {
                  }
               }
               break;
            }
            case SDL_QUIT:
            {
               done = true;
               break;
            }
            default:
            {
               break;
            }
         }
      }

      GraphicsUtil::getInstance()->pushInput(event);
   }

   player->step(timePassed);

   stepNPCs(timePassed);

   return !done;
}

TileEngine::~TileEngine()
{
   delete scheduler;
   delete scriptEngine;
   delete dialogue;
   delete top;
}
