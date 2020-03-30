#include "GameMode.h"
#include "GameController.h"

GameMode::GameMode(const GameController *controller, const Player_ &whitePlayer, const Player_ &blackPlayer)
    : controller(controller)
{
    this->blackPlayer = blackPlayer;
    this->whitePlayer = whitePlayer;
    gameRunning = false;
}

GameMode::~GameMode()
{
}

void GameMode::Run()
{
    controller->UpdateBoard();
    gameRunning = true;
    while (gameRunning)
    {

        if (gamestate.GetListOfMoves().empty())
        {
            if (gamestate.GetSideOnTurn() == white)
            {
                controller->SignalGameOver(black);
            }
            else
            {
                controller->SignalGameOver(white);
            }
            gameRunning = false;
            break;
        }

        Move move = playerOnTurn->GetMove(gamestate);

        if (!gameRunning)
        {
            break;
        }

        gamestate.ExecuteMove(move);

        EndTurn();
    }
}

void GameMode::Stop()
{
    gameRunning = false;
}

bool GameMode::IsGameRunning()
{
    return gameRunning;
}

void GameMode::Setup(const string &fen)
{
    FenParser fenParser;
    fenParser.ReadFEN(gamestate, fen);
    if (gamestate.GetSideOnTurn() == white)
    {
        playerOnTurn = whitePlayer;
    }
    else
    {
        playerOnTurn = blackPlayer;
    }
}

string GameMode::GetFenRepresentation()
{
    FenParser fenParser;
    return fenParser.WriteFEN(gamestate);
}

void GameMode::EndTurn()
{
    if (gamestate.GetSideOnTurn() == white)
    {
        playerOnTurn = whitePlayer;
    }
    else
    {
        playerOnTurn = blackPlayer;
    }
    controller->UpdateBoard();
}

const State &GameMode::GetGameState() const
{
    return gamestate;
}