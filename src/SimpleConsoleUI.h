#ifndef SIMPLECONSOLE_H
#define SIMPLECONSOLE_H

#include "UI.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
/**
  * SimpleConsoleUI class.
  * This class implements UI class Interface.
  * This class represents very simple console UI 
  * implemented just with c++ standart library
  */
class SimpleConsoleUI : public UI
{
public:
  /**
  * SimpleConsoleUI class constructor.
  * @param controller pointer to program controller.
  */
  SimpleConsoleUI(GameController *controller);
  void RenderGamestate(const State &GameState) const override;
  void RenderGameOver(const string &winner) const override;
  void GameInteraction() override;
  void CloseUI() override;
  void OpenUI() override;

private:
  bool runnunig; /**< state of the ui */
  string ReadCommand(); /**< read command from promt */
  void MainMenu(); /**< Main menu implementation */
  void NewGameMenu(); /**< New Game Menu implementattion */

  void ShowMainMenu(); /**< Render menu */
  void ShowNewGameMenu(); /**< render menu*/
  void ShowGameMenu(); /**< render menu */

  //commands:
  const string exitCmd = "exit";
  const string moveCmd = "move";
  const string quitCmd = "quit";
  const string saveCmd = "save";
  const string loadCmd = "load";
  const string newGameCmd = "newgame";
  const string singleplayerCmd = "singleplayer";
  const string multiplayerCmd = "multiplayer";

  //error messages:
  const string invalidMoveMsg = "invalid move !";
  const string unknownCommandMsg = "unknown command !";
  const string SavefileLoadErrorMsg = "unable to load the game !";
};

#endif