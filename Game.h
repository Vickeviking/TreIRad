#ifndef MYCLASS_H_ // #include guards
#define MYCLASS_H_
#include "Board.h"
#include "raylib.h"
#include <vector>
#include "Player.h"
#include "Piece.h"
class Game
{
private:
    std::vector<Player> playerVector = {};
    int state{0}; // state
    int windowDimensions[2] = {1080, 720};
    bool Alive{};
    bool Restart{};
    int Grid{};
    bool AllpiecesPlayed{};
    bool PlayerOneTurn{true};
    Player *playerTarget{};
    float Radius{30};
    int Turns{};
    Board board{486, 486, (1080 / 2) - 243, (720 / 2) - 243};
    Vector2 CollisionCircle{};
    Vector2 *PosPointer{board.getPossitionArray()};
    int *positionTakenPointer{board.getPositionTaken()};
    bool playerOneWon{};

public:
    Game(int i);
    void Reset();
    void Init();
    void Start();
    void Draw();
    void DrawPause();
    void DrawStart();
    void DrawSettings();
    void PlayerOneWon(bool playerOneHasWon)
    {
        playerOneWon = playerOneHasWon;
    }
    Board getboard()
    {
        return board;
    }
    void setState(int _state) { state = _state; } // state
    int getState() { return state; }
    int *getWindowDimensions() { return windowDimensions; }
    bool getAlive()
    {
        return Alive;
    }
    ~Game();
};

#endif