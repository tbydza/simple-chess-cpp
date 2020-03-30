#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const GameController *controller)
    : controller(controller)
{
}

Move HumanPlayer::GetMove(const State &gamestate) const
{
    return controller->GetPlayerInput();
}
