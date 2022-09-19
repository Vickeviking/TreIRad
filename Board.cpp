#include "Board.h"

Board::Board(float Width, float Height, float boardx, float boardy) : _Width(Width), _Height(Height), _Boardx(boardx), _Boardy(boardy)
{
    SetupBoardDimensions();
}

void Board::DrawBoard()
{

    // empty for now
}

void Board::SetupBoardDimensions()
{
    _Space = _Width / 18;

    for (int i = 0; i < 9; i++)
    {
        ArrayPositionTaken[i] = {0};
    }

    PosArray[0].x = {_Space + (_Space * 4.f) - 80};
    PosArray[1].x = {(_Space * 2.f) + (_Space * 3.5f) + (_Space + (_Space * 4.f)) - 80};
    PosArray[2].x = {(_Space * 4.f) + (_Space * 3) + ((_Space) + (_Space * 4.f) + ((_Space * 4.f))) - 80};
    PosArray[3].x = {_Space + (_Space * 4) - 80};
    PosArray[4].x = {(_Space * 2.f) + (_Space * 3.5f) + (_Space + (_Space * 4.f)) - 80};
    PosArray[5].x = {(_Space * 4.f) + (_Space * 3) + ((_Space) + (_Space * 4.f) + ((_Space * 4.f))) - 80};
    PosArray[6].x = {_Space + (_Space * 4) - 80};
    PosArray[7].x = {(_Space * 2.f) + (_Space * 3.5f) + (_Space + (_Space * 4.f)) - 80};
    PosArray[8].x = {(_Space * 4.f) + (_Space * 3.f) + ((_Space) + (_Space * 4.f) + ((_Space * 4.f))) - 80};

    PosArray[0].y = {_Space + 20};
    PosArray[1].y = {_Space + 20};
    PosArray[2].y = {_Space + 20};
    PosArray[3].y = {_Space + (_Space * 4.f) + (_Space * 2.f) + 20};
    PosArray[4].y = {_Space + (_Space * 4.f) + (_Space * 2.f) + 20};
    PosArray[5].y = {_Space + (_Space * 4.f) + (_Space * 2.f) + 20};
    PosArray[6].y = {_Space + (_Space * 8.f) + (_Space * 4.f) + 20};
    PosArray[7].y = {_Space + (_Space * 8.f) + (_Space * 4.f) + 20};
    PosArray[8].y = {_Space + (_Space * 8.f) + (_Space * 4.f) + 20};
}

bool Board::CheckWin(Player *player)
{
    bool win = {false};

    int Ap[9] = {};
    for (int i = 0; i < 9; i++)
    {
        Ap[i] = player->getPositionArray()[i];
    }

    int d1Points = {};
    int d2Points = {};

    int c1, c2, c3 = {};
    int r1, r2, r3 = {};

    // check diagonals
    if (Ap[0] == 1 && Ap[4] == 1 && Ap[8] == 1)
    {
        win = true;
        return true;
    }
    if (Ap[2] == 1 && Ap[4] == 1 && Ap[6] == 1)
    {
        win = true;
        return true;
    }

    // check columns
    if (Ap[0] == 1 && Ap[3] == 1 && Ap[6] == 1)
    {
        win = true;
        return true;
    }
    if (Ap[1] == 1 && Ap[4] == 1 && Ap[7] == 1)
    {
        win = true;
        return true;
    }
    if (Ap[2] == 1 && Ap[5] == 1 && Ap[8] == 1)
    {
        win = true;
        return true;
    }

    // check rows
    if (Ap[0] == 1 && Ap[1] == 1 && Ap[2] == 1)
    {
        win = true;
        return true;
    }
    if (Ap[3] == 1 && Ap[4] == 1 && Ap[5] == 1)
    {
        win = true;
        return true;
    }
    if (Ap[6] == 1 && Ap[7] == 1 && Ap[8] == 1)
    {
        win = true;
        return true;
    }

    return win;
}