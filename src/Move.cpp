#include "Move.h"
Move::Move() : src(Position(0, 0)), dst(Position(0, 0))
{
}

Move::Move(const Position &src, const Position &dst, bool capture, bool castling) : src(src), dst(dst)
{
    this->capture = capture;
    this->castling = castling;
}

bool Move::IsCastling() const
{
    return castling;
}

bool Move::IsCapture() const
{
    return capture;
}

Position Move::GetDestinationPosition() const
{
    return dst;
}

Position Move::GetSourcePosition() const
{
    return src;
}

bool Move::operator==(const Move &other) const
{
    return src == other.src &&
           dst == other.dst;
}
