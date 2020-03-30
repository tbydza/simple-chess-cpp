#include "GameController.h"

bool GameController::GeneratePlayerMove(const Position &src, const Position &dst)
{
    Move possibleMove;

    if (!game->GetGameState().getTile(src).HasFigure())
    {
        return false;
    }

    if (game->GetGameState().getTile(src).GetFigure()->GetSide() != game->GetGameState().GetSideOnTurn())
    {
        return false;
    }

    if (!game->GetGameState().getTile(dst).HasFigure())
    {
        possibleMove = Move(src, dst, false);
    }
    else
    {
        if (game->GetGameState().getTile(dst).GetFigure()->GetSide() != game->GetGameState().GetSideOnTurn())
        {
            possibleMove = Move(src, dst, true);
        }
        else
        {
            return false;
        }
    }
    vector<Move> allMoves = game->GetGameState().GetListOfMoves(game->GetGameState().getTile(src).GetFigure());

    vector<Move>::iterator it;
    if ((it = find(allMoves.begin(), allMoves.end(), possibleMove)) != allMoves.end())
    {

        playerMoveCache = *it;
    }
    else
    {
        return false;
    }

    return true;
}

GameController::GameController()
{
    interface = make_shared<SimpleConsoleUI>(this);
}

void GameController::NewGame(bool multiplayerEnable)
{
    if (multiplayerEnable)
    {
        game = make_shared<MultiplayerMode>(this, make_shared<HumanPlayer>(this), make_shared<HumanPlayer>(this));
    }
    else
    {
        game = make_shared<SingleplayerMode>(this, make_shared<HumanPlayer>(this), make_shared<ComputerPlayer>());
    }
    game->Setup();
    game->Run();
}

bool GameController::LoadGame(const string &fileName)
{
    FileIO fileIO;
    pair<string, string> gameData;
    try
    {
        gameData = fileIO.Load(fileName);
    }
    catch (const exception &e)
    {
        return false;
    }

    if (gameData.first == pvp)
    {
        game = make_shared<MultiplayerMode>(this, make_shared<HumanPlayer>(this), make_shared<HumanPlayer>(this));
    }
    else if (gameData.first == pve)
    {
        game = make_shared<SingleplayerMode>(this, make_shared<HumanPlayer>(this), make_shared<ComputerPlayer>());
    }
    else
    {
        return false;
    }

    try
    {
        game->Setup(gameData.second);
    }
    catch (const exception &e)
    {
        return false;
    }

    game->Run();
    return true;
}

bool GameController::SaveGame(const string &fileName) const
{
    FileIO fileIO;
    pair<string, string> gameData;

    if (dynamic_cast<SingleplayerMode *>(game.get()) != nullptr)
    {
        gameData.first = pve;
    }
    else if (dynamic_cast<MultiplayerMode *>(game.get()) != nullptr)
    {
        gameData.first = pvp;
    }

    gameData.second = game->GetFenRepresentation();

    try
    {
        fileIO.Save(fileName, gameData);
    }
    catch (const exception &e)
    {
        return false;
    }
    return true;
}

Move GameController::GetPlayerInput() const
{
    interface->GameInteraction(); //gives control to UI
    return playerMoveCache;
}

void GameController::QuitGame()
{
    game->Stop();
}

void GameController::UpdateBoard() const
{
    interface->RenderGamestate(game->GetGameState());
}

void GameController::StartProgram()
{
    interface->OpenUI();
}

void GameController::ExitProgram()
{
    if (game.operator bool() && game->IsGameRunning())
    {
        game->Stop();
    }
    interface->CloseUI();
}

void GameController::SignalGameOver(Side winningSide) const
{
    if (winningSide == white)
    {
        interface->RenderGameOver("WHITE");
    }
    else
    {
        interface->RenderGameOver("BLACK");
    }
}