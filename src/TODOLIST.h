#error "This file (TODOLIST.h) should NOT be compiled. It is only in the source tree for use by Doxygen."

/**
 * \todo Complete and populate the Exodus Draconis website (PLEASE).
 * \todo Find a better way to do the todo list and to prioritize tasks.
 * \todo Consolidate Story and Reqs wikis.
 * \todo Create new Code wiki.
 */
void OrganizationTodoList(void);

/**
 * \todo Sound needs to handle and signal instruction IDs
 * \todo Potential deadlock: What if a dialogue line has an embedded script that calls to the dialogue controller and yields? Is this important?
 * \todo Dialogue Controller needs to have "speed up" on holding of the space bar
 * \todo Dialogue Controller needs a blinking cursor to indicate finished dialogue.
 * \todo Further integration of scripts into Tile Engine, followed by unit tests for all the script functions
 * \todo Document all of the Resources (Music, Sound, Tileset, Region), and the Resource abstract class
 * \todo Remove references to namespace gcn outside of edwt (as many as possible if not all)
 * \todo Complete or remove ScriptException class, as it is currently empty and pointless.
 * \todo Document ScriptException when it is completed.
 * \todo Add NPCs to the game.
 * \todo Create an NPC controller for the Tile Engine.
 * \todo Implement semi-coroutines in the NPC controller using Lua.
 * \todo Dialogue Controller should inherit from a generic "scrolling text controller" that takes a textbox argument to write to
   * To do this, a full rewrite of the Dialogue Controller might be necessary, due to some tight coupling in the class at the moment
 * \todo Add the player character to the game, and make him respond to user input.
 * \todo Update ResourceLoader to include reference counting and LRU resource eviction.
 * \todo Integrate GraphicsUtil stuff from Solstice (synchronous fading and texture load, mainly).
 * \todo Change OpenGLTTF to remove dependency on gcn::Image
 * \todo Create a "Controls" class that translates pressed keys/buttons to controller-agnostic instructions based on user options.
 * \todo Create some test harnesses/sandboxes for different pieces of the engine.
 * \todo Create unit tests for the various pieces of the game.
 * \todo Create an options menu with persistence.
 * \todo Create an About/Credits screen
 * \todo Organize the global code folder and try to create some new folders for organization
 * \todo Remove Tileset dependency on SDL by abstracting texture load code into GraphicsUtil
 * \todo Tileset passibility matrix uses a bool (1 word) for each entry; it should only need to use one bit per entry.
 * \todo Move GL drawing code in Tileset to GraphicsUtil (less coupling)
 * \todo Consider changing the quad drawing code by using GL_ORTHO_2D
 * \todo Consider how to change the embedded script markup to avoid having to escape single-quotes in string parameters
 */
void DevelopmentTodoList(void);

/**
 * \todo Create a slider for volume control of music.
 * \todo Create a slider for volume control of sound.
 * \todo Create a dropdown for known screen resolutions (Width x Height x BitsPerPixel)
 * \todo Create a slider or list for controlling dialogue speed.
 * \todo Create a demo of the dialogue speed that runs some text when the speed changes.
 * \todo Create a slider for memory usage by the resource loader (requires the resource loader to be finished)
 * \todo Create a submenu for changing control schemes (key associations, gamepad calibration, etc.)
 */
void OptionsMenuTodoList(void);

/**
 * \todo freezeUserInput/startCutScene - don't allow user input (begin a cutscene)
 * \todo permitUserInput/endCutScene - allow user input (end a cutscene)
 * \todo playSound function - play a sound (possibly blocking until sound is finished)
 * \todo playMusic function - play a song (stop the currently playing song)
 * \todo fadeMusic function - fade a song out with a given time delay (possibly blocking until the song is faded)
 * \todo setLoopPoints function - set new looping points for a song (song continues playing with new points)
 */
void ScriptFunctionsTodoList(void);

/**
 * \todo Add Academic Magic descriptions and crests from DA page
 * \todo Come up with a title for Part 2.
 * \todo Finish descriptions of Parts 1-3.
 * \todo Complete the description of the Crystal Guardian, and come up with a name for her.
 * \todo Fill in other blanks as necessary.
 */
void StoryTodoList(void);
