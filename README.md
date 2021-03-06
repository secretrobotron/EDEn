EDEn README
===========

EDEn (the Exodus Draconis Engine) is a free and open-source engine used to create top-down, 2D RPGs with 3D effects. Aside from the usual trimmings one would expect from the genre, the engine aims to also enable some gameplay elements typically found in adventure games.

The initial purpose of this engine was to facilitate the creation of a very specific game (Exodus Draconis, for which the engine is named). While development of the game continues, the engine will contain common code and utilities created along the way that may aid in the development of other RPGs.

EDEn is programmed in C++ and uses SDL for graphics and audio. By exposing C++ functionality as a Lua API, EDEn allows game developers to develop and tweak gameplay, quests and stories on the fly without requiring the source to be recompiled. The engine can also handle a variety of image and audio assets supported by SDL_image and SDL_mixer, respectively.

In general, EDEn aims to help game designers quickly turn RPG stories, gameplay and level designs into playable RPGs. 

License and Copyright
---------------------

Most of the code is Copyright 2012 Noam Chitayat. Contributors retain copyright to their original contributions.

The EDEn source is released under the terms of the Ruby License, with the following exceptions:

* Code in the guichan folder or under the gcn namespace is part of the Guichan GUI library version 0.8.2.

	Guichan is copyright 2004-2012 Olof Naessén and Per Larsson. All rights reserved. 

* Code in the json folder or under the Json namespace is part of the JsonCpp JSON parsing library.

	JsonCpp is copryright 2007-2012 Baptiste Lepilleur. Distributed under MIT license, or public domain if desired and recognized in your jurisdiction.

* Code in the tinyxml folder is part of the TinyXML XML parsing library.

	TinyXML is copyright 2000-2012 Lee Thomason. 

* Code in the LuaWrapper folder is part of the LuaWrapper library.

	LuaWrapper is copyright 2010-2012 Alexander Ameson.

Art and audio assets are copyright their creators. For specific asset credits, please refer to ASSETS.txt.

For the full text of the Ruby license in use, please refer to the LICENSE.txt file.

Dependencies
------------

EDEn depends on the following development libraries to build the source:

* SDL 1.2
* SDL_image 1.2
* SDL_ttf 2.0
* SDL_mixer 1.2
* Lua 5.1

Windows developers will also need the Windows implementation of dirent.h.

EDEn requires the equivalent runtime libraries to execute.

Links
-----

* SDL Cross-platform Library - http://www.libsdl.org
* Guichan GUI library - http://guichan.sourceforge.net
* Lua Programming Language - http://www.lua.org
* JsonCpp library - http://jsoncpp.sourceforge.net/
* TinyXml library - http://www.grinninglizard.com/tinyxml/
* dirent.h implementation for Windows - http://www.softagalleria.net/dirent.php

Running EDEn
------------

To build EDEn by command-line, navigate to the root directory and run the following commands:

	cmake .
	make
	./eden

On Windows, CMake can be used to create a Visual Studio solution that can be used to build and run the source.

On Mac OS X, CMake can be used to create an XCode project that can be used to build and run the source.

