/*
 *  This file is covered by the Ruby license. See LICENSE.txt for more details.
 *
 *  Copyright (C) 2007-2012 Noam Chitayat. All rights reserved.
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "MovementDirection.h"

class Spritesheet;
class Animation;

/**
 * A sprite is a movable object that can go through different animations or
 * static frames. Sprites are used to represent projectiles, characters,
 * anything that isn't background.
 */
class Sprite
{
   /** The spritesheet containing this sprite's frames. */
   Spritesheet* sheet;

   /** The index of the current static frame within the sheet. -1 if an animation is used instead. */
   int frameIndex;
   
   /** The animation structure to use to animate this sprite. NULL if a static frame is used instead. */
   Animation* animation;
   
   /** The name of the current frame/animation being used. */
   std::string currName;
   
   /** The direction that the current frame/animation is facing. */
   MovementDirection currDirection;
   
   /**
    * @param direction A direction to convert to a string.
    *
    * @return The string to append to a frame or animation for a given direction.
    */
   std::string toDirectionString(MovementDirection direction);

   public:

      /**
       * Constructor.
       *
       * @param sheet The spritesheet to use to draw this sprite.
       */
      Sprite(Spritesheet* sheet);

      /**
       * Clears any existing frame or animation information.
       */
      void clearCurrentFrame();

      /**
       * Change the spritesheet for this sprite (changes the look of it)
       *
       * @param newSheet The new Spritesheet to use.
       */
      void setSheet(Spritesheet* newSheet);
   
      /**
       * Set a static frame to draw for this sprite.
       *
       * @param frameName The name of the static frame.
       * @param direction The direction that the new sprite should face.
       */
      void setFrame(const std::string& frameName, MovementDirection direction);

      /**
       * Set an animation to draw for this sprite.
       *
       * @param animationName The name of the animation.
       * @param direction The direction that the new sprite should face.
       */
      void setAnimation(const std::string& animationName, MovementDirection direction);

      /**
       * A logic step for the sprite. Currently just advances the animation if
       * there is one.
       *
       * @param timePassed The amount of time to advance forward.
       */
      void step(long timePassed);

      /**
       * Draws the sprite at the specified location.
       *
       * @param x The x-location to draw at.
       * @param y The y-location to draw at.
       */
      void draw(int x, int y) const;

      /**
       * Destructor.
       */
      ~Sprite();
};

#endif
