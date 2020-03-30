#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
}
Move ComputerPlayer::GetMove(const State &gamestate) const
{
    return ChooseMove(gamestate.GetListOfMoves());
}

Move ComputerPlayer::ChooseMove(const vector<Move> &possibleMoves) const
{
    return possibleMoves.at(rand() % possibleMoves.size());
}