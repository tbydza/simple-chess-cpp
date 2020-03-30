#include "Rook.h"

Rook::Rook(Side side, const Position &position) : Figure(side, position)
{
    actions.push_back(Action(shift, 1, 0));
    actions.push_back(Action(shift, 0, 1));
    actions.push_back(Action(shift, -1, 0));
    actions.push_back(Action(shift, 0, -1));
}

string Rook::ToString() const
{
    if (side == white)
    {
        return "R";
    }
    else
    {
        return "r";
    }
}

Figure_ Rook::Clone() const
{
    return Figure_(new Rook(*this));
}