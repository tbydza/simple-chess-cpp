#include "Figure.h"

Figure::Figure(Side side, const Position &position) : position(position)
{
    this->side = side;
}

Side Figure::GetSide() const
{
    return side;
}

const Position &Figure::GetPosition() const
{
    return position;
}

void Figure::SetPosition(const Position &position)
{
    this->position = position;
}

Figure::~Figure()
{
}

const vector<Action> Figure::GetActions() const
{
    return actions;
}
