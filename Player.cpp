#include "Player.h"

Player::Player(bool IsTeamOne) : IsTeamOne(IsTeamOne)
{
    TargetPiece = { &pieceVector[0]};
    if (IsTeamOne)
    {
        x = 50;
    }
    else
    {
        x = 770;
    }

    Piece p1(x + 60, 600);
    Piece p2(x + 130, 600);
    Piece p3(x + 200, 600);

    pieceVector = {p1, p2, p3};

    for (int i = 0; i < 9; i++)
    {
        ArrayPositionTaken[i] = 0;
    }
    
}

Player::~Player()
{
}