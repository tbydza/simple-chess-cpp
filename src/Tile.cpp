#include "Tile.h"

bool Tile::HasFigure() const
{
    return figure.operator bool();
}

void Tile::SetFigure(const Figure_ &figure)
{
    this->figure = figure;
}

Figure_ Tile::GetFigure() const
{
    return figure;
}