#include "Queen.h"

Queen::Queen(Side side, const Position &position) : Figure(side, position)
{
    actions.push_back(Action(shift, 1, 0));
    actions.push_back(Action(shift, 0, 1));
    actions.push_back(Action(shift, -1, 0));
    actions.push_back(Action(shift, 0, -1));

    actions.push_back(Action(shift, 1, 1));
    actions.push_back(Action(shift, 1, -1));
    actions.push_back(Action(shift, -1, 1));
    actions.push_back(Action(shift, -1, -1));
}

string Queen::ToString() const
{
    if (side == white)
    {
        return "Q";
    }
    else
    {
        return "q";
    }
}

Figure_ Queen::Clone() const
{
    return Figure_(new Queen(*this));
}
