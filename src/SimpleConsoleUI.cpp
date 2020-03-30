#include "SimpleConsoleUI.h"
#include "GameController.h"

SimpleConsoleUI::SimpleConsoleUI(GameController *controller)
    : UI(controller)
{
}

void SimpleConsoleUI::RenderGamestate(const State &gamestate) const
{
    cout << endl;
    cout << "    ";
    for (int i = 0; i < 8; ++i)
    {
        cout << Position(i, 0).Column() << " ";
    }
    cout << endl;
    cout << "   -----------------" << endl;
    for (int i = 7; i >= 0; --i)
    {
        cout << Position(0, i).Row() << " | ";
        for (int j = 0; j < 8; ++j)
        {
            if (!gamestate.getTile(Position(j, i)).HasFigure())
            {
                cout << ".";
            }
            else
            {
                cout << gamestate.getTile(Position(j, i)).GetFigure()->ToString();
            }
            cout << " ";
        }
        cout << "| " << Position(0, i).Row() << endl;
    }
    cout << "   -----------------" << endl;

    cout << "    ";
    for (int i = 0; i < 8; ++i)
    {
        cout << Position(i, 0).Column() << " ";
    }
    cout << endl;

    if (gamestate.GetSideOnTurn() == white)
    {
        cout << "white ";
    }
    else
    {
        cout << "black ";
    }
    cout << gamestate.GetTurnCount() << endl;
}

void SimpleConsoleUI::RenderGameOver(const string &winner) const
{
    cout << "--------------" << endl;
    cout << "winner: " << winner << endl;
    cout << "--------------" << endl;
}

void SimpleConsoleUI::CloseUI()
{
    runnunig = false;
}
void SimpleConsoleUI::OpenUI()
{
    runnunig = true;
    MainMenu();
}

void SimpleConsoleUI::ShowNewGameMenu()
{
    cout << "--------------" << endl;
    cout << "|  NEW GAME  |" << endl;
    cout << "--------------" << endl;
    cout << singleplayerCmd << endl;
    cout << multiplayerCmd << endl;
    cout << quitCmd << endl;
    cout << exitCmd << endl;
    cout << "--------------" << endl;
}

void SimpleConsoleUI::ShowGameMenu()
{
    cout << moveCmd << " <Pos> <Pos>" << endl;
    cout << quitCmd << endl;
    cout << saveCmd << " <savefile>" << endl;
    cout << exitCmd << endl;
    cout << "--------------" << endl;
}

void SimpleConsoleUI::ShowMainMenu()
{
    cout << "--------------" << endl;
    cout << "| MAIN  MENU |" << endl;
    cout << "--------------" << endl;
    cout << newGameCmd << endl;
    cout << loadCmd << " <savefile>" << endl;
    cout << exitCmd << endl;
    cout << "--------------" << endl;
}

string SimpleConsoleUI::ReadCommand()
{
    string command;
    cout << ": " << flush;
    cin >> command;
    cout << "==============" << endl;
    cout << endl;
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    return command;
}

void SimpleConsoleUI::MainMenu()
{
    while (runnunig)
    {
        ShowMainMenu();

        string command = ReadCommand();
        if (command == exitCmd)
        {
            controller->ExitProgram();

            break;
        }
        else if (command == newGameCmd)
        {
            NewGameMenu();
        }
        else if (command == loadCmd)
        {
            string filename;
            cin >> filename;

            if (!controller->LoadGame(filename))
            {
                cout << SavefileLoadErrorMsg << endl;
            }
        }
        else
        {
            cout << unknownCommandMsg << endl;
        }
    }
}

void SimpleConsoleUI::GameInteraction()
{

    while (true)
    {

        string command = ReadCommand();
        if (command == exitCmd)
        {
            controller->ExitProgram();
            break;
        }
        else if (command == quitCmd)
        {
            controller->QuitGame();
            break;
        }
        else if (command == saveCmd)
        {
            string filename;
            cin >> filename;
            controller->SaveGame(filename);
        }
        else if (command == moveCmd)
        {
            string argument1, argument2;
            cin >> argument1;
            cin >> argument2;

            try
            {
                Position src(argument1);
                Position dst(argument2);
                if (controller->GeneratePlayerMove(src, dst))
                {
                    break;
                }
            }
            catch (const exception &e)
            {
                cout << invalidMoveMsg << endl;
            }
        }
        else
        {
            cout << unknownCommandMsg << endl;
        }
    }
}

void SimpleConsoleUI::NewGameMenu()
{
    ShowNewGameMenu();
    string command = ReadCommand();
    if (command == exitCmd)
    {
        controller->ExitProgram();
        return;
    }
    else if (command == quitCmd)
    {
        return;
    }
    else if (command == singleplayerCmd)
    {
        ShowGameMenu();
        controller->NewGame(false);
    }
    else if (command == multiplayerCmd)
    {
        controller->NewGame(true);
    }
    else
    {
        cout << unknownCommandMsg << endl;
    }
}
