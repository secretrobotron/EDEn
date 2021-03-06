/*
 *  This file is covered by the Ruby license. See LICENSE.txt for more details.
 *
 *  Copyright (C) 2007-2012 Noam Chitayat. All rights reserved.
 */

#ifndef GRAPHICS_UTIL_H
#define GRAPHICS_UTIL_H

#include "Singleton.h"

struct SDL_Surface;
union SDL_Event;

namespace gcn
{
   class SDLInput;
   class OpenGLGraphics;
   class OpenGLSDLImageLoader;
   class Gui;
   class Container;
};
    
namespace edwt
{
   class Container;
   class OpenGLTrueTypeFont;
};

namespace shapes
{
   struct Size;
};

typedef unsigned int GLuint;

/**
 * All cross-class utilities for graphic functionality, such as initialization, effects, and drawing
 * are encapsulated in this singleton class.
 *
 * Note: This class is a singleton.
 *
 * @author Noam Chitayat
 */
class GraphicsUtil : public Singleton<GraphicsUtil>
{
   /** The screen surface */    
   static SDL_Surface* screen;

   /** The Guichan SDL input driver */
   gcn::SDLInput* input;

   /** The Guichan OpenGL Graphics driver */
   gcn::OpenGLGraphics* graphics;

   /** The Guichan OpenGL image loader (for loading images via SDL) */
   gcn::OpenGLSDLImageLoader* imageLoader;

   /** A Gui object - binds all the drivers together */
   gcn::Gui* gui;
   
   /** A top-level container bound to the GUI. */
   edwt::Container* guiContainer;
   
   /** The current container shown inside the top-level container. */
   gcn::Container* top;

   /** The global default font */
   edwt::OpenGLTrueTypeFont* font;

   /** The x-offset to draw at (in pixels). */
   int currentXOffset;

   /** The y-offset to draw at (in pixels). */
   int currentYOffset;

   /**
    * Initializes SDL audio and video bindings
    * Initializes SDL mixer and TTF libraries
    * Initializes an OpenGL viewport and projection
    */
   void initSDL();

   /**
    * Initializes the Guichan library for use with OpenGL via SDL.
    */
   void initGuichan();

   protected:
      /** 
       * Constructor.
       * Initializes SDL and OpenGL.
       * Initialize Guichan GUI drivers for OpenGL.
       */
      virtual void initialize();
   
      /**
       * Singleton destructor.
       * Cleans up the following:
       * - drivers
       * - global font
       * - the SDL TrueTypeFont library
       * - the SDL layer
       */
      virtual void finish();

   public:
      /** The screen width (currently HARDCODED) */
      static const unsigned int width = 800;
   
      /** The screen height (currently HARDCODED) */
      static const unsigned int height = 600;
   
      /**
       * @return The width of the screen
       */
      int getWidth();

      /**
       * @return The height of the screen
       */
      int getHeight();

      /**
       * Set the widget container to draw to screen.
       *
       * @param top The widget container to be used as the top-level container
       */
      void setInterface(gcn::Container* top);

      /**
       * Flush any enqueued GL commands and then flip the screen buffer
       */
      void flipScreen();
   
      /**
       * Run GUI widget logic
       */
      void stepGUI();
   
      /**
       * Draw GUI widgets to the screen
       */
      void drawGUI();

      /**
       * Push an SDL input event to the widgets
       *
       * @param event the input event to send to the widgets
       */
      void pushInput(SDL_Event event);

      /**
       * Sets a camera offset to begin drawing at. Note that this offset is
       * absolute; the offset is from the origin, rather than from the current
       * offset.
       *
       * @param xOffset The x-offset to draw at.
       * @param yOffset The y-offset to draw at.
       */
      void setOffset(int xOffset, int yOffset);

      /**
       * Resets the camera offset to 0.
       */
      void resetOffset();

      /** 
       *  Graphical effect: Fade to a specific colour in a specified time period
       *
       *  @param red   The amount of red   (0.0f <= red <= 1.0f)
       *  @param green The amount of green (0.0f <= green <= 1.0f)
       *  @param blue  The amount of blue  (0.0f <= blue <= 1.0f)
       *  @param delay The amount of time taken for the fade (in milliseconds)
       */
      void FadeToColor(float red, float green, float blue, int delay);
   
      /**
       * Clear the color buffers and reset the model matrix
       * \todo Come up with a better name for this (though that suggestion indicates that this method may not be good design).
       */
      void clearBuffer();
};

#endif

