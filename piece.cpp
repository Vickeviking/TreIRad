#include "Piece.h"

Piece::Piece(int startX, int startY):
StartPositionX(startX),
StartPositionY(startY)
{
    x = startX;
    y = startY;
}

void Piece::goToStart()
{
    x = StartPositionX;
    y = StartPositionY;
}

Piece::~Piece()
{
}