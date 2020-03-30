#include "Bishop.h"

Bishop::Bishop(Side side, const Position &position) : Figure(side, position)
{
    actions.push_back(Action(shift, 1, 1));
    actions.push_back(Action(shift, 1, -1));
    actions.push_back(Action(shift, -1, 1));
    actions.push_back(Action(shift, -1, -1));
}

string Bishop::ToString() const
{
    if (side == white)
    {
        return "B";
    }
    else
    {
        return "b";
    }
}
Figure_ Bishop::Clone() const
{
    return Figure_(new Bishop(*this));
}