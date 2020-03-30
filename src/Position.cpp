#include "Position.h"

Position::Position(int x, int y)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        throw exception();
    }
    this->x = x;
    this->y = y;
}
Position::Position(const Position &src)
{
    this->x = src.x;
    this->y = src.y;
}
Position::Position(Position &&src)
{
    this->x = src.x;
    this->y = src.y;
}
Position &Position::operator=(const Position &src)
{
    this->x = src.x;
    this->y = src.y;
    return *this;
}
Position Position::operator+(const pair<int, int> &direction) const
{
    return Position(x + direction.first, y + direction.second);
}

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

Position::~Position()
{
}

Position::Position(char column, int row)
{
    if (column < 'a' || column > 'h' || row < 1 || row > 8)
    {
        throw exception();
    }

    this->x = XFromColumn(column);
    this->y = YFromRow(row);
}

Position::Position(const string &pos) : Position(pos.at(0), pos.at(1) - '0')
{
}

char Position::Column() const
{
    return (char)('a' + x);
}

int Position::Row() const
{
    return y + 1;
}

int Position::GetX() const
{
    return x;
}
int Position::GetY() const
{
    return y;
}

bool Position::IsNextTo(const Position &pos) const
{
    if (this->x == pos.x && abs(this->y - pos.y) == 1)
        return true;

    if (this->y == pos.y && abs(this->x - pos.x) == 1)
        return true;

    return false;
}

string Position::ToString() const
{
    ostringstream oss;
    oss << Column() << Row();
    return oss.str();
}

int Position::XFromColumn(char column)
{
    return column - 'a';
}

int Position::YFromRow(int row)
{
    return row - 1;
}
