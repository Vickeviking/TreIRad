#ifndef MYCLASSP_ // #include guards
#define MYCLASSP_
#include "Player.h"
#include "raylib.h"
class Board
{
private:
    float _Boardx{};
    float _Boardy{};
    float _Width{};
    float _Height{};
    int ArrayPositionTaken[9]{};
    Vector2 PosArray[9];
    float _Space{};

public:
    bool CheckWin(Player *player);
    bool CanPlace(std::vector<Player> playerVector);
    Board(float Width, float Height, float boardx, float boardy);
    void DrawBoard();
    void SetupBoardDimensions();

    void resetArrayPositionTaken()
    {
        for (int i = 0; i < 9; i++)
        {
            ArrayPositionTaken[i] = 0;
        }
    }

    float getBoardx()
    {
        return _Boardx;
    }
    float getBoardy()
    {
        return _Boardy;
    }

    float getBoardWidth()
    {
        return _Width;
    }
    float getBoardHeight()
    {
        return _Height;
    }
    float getSpace()
    {
        return _Space;
    }

    Vector2 *getPossitionArray()
    {
        return PosArray;
    }

    int *getPositionTaken()
    {
        return ArrayPositionTaken;
    }
};
#endif
