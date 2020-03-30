
/** \mainpage Chess program
 * 
 * Author: Tomáš Bydžovský bydzoto1@fit.cvut.cz
 * 
 * \section intro_sec Introduction
 *
 * This program is chess game.
 * You can play against computer (singleplayer) 
 * or against another human (multiplayer).
 * During the game you can save your progress to savefile and 
 * later load it and resume the gameplay.
 * Implementation of the chess engine allows special rules such as 
 * en passant, castling and pawn promotion.
 * 
 * \section controls_sec Controls
 * 
 * The game has very simple console user interface. There is a menu with options to choose.
 * These options are also programs commands.
 * In order to choose option you need to type the option (command) 
 * to the prompt under the menu and hit <Enter>.
 * 
 * \subsection mainMenu Main Menu
 * \par Availible commands: 
 *      newgame <BR>
 *      load \<savefile name> <BR>
 *      exit <BR> 
 * \subsection newgameMenu New Game Menu
 * \par Availible commands: 
 *      singleplayer <BR>
 *      multiplayer <BR>
 *      quit <BR>
 *      exit <BR>
 * \subsection gameMenu Game menu
 * \par Availible commands: 
 *      move \<Position> \<Position> <BR>
 *      save \<savefile name> <BR>
 *      quit <BR>
 *      exit <BR>
 * 
 */

#include "GameController.h"

using namespace std;

int main()
{
    GameController gameController;
    gameController.StartProgram();
    return 0;
}
