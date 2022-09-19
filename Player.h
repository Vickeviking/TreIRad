#ifndef MYCLAS_ // #include guards
#define MYCLAS_
#include <vector>
#include "Piece.h"
class Player
{
private:
    std::vector<Piece> pieceVector;
    bool IsTeamOne{};
    int x{};
    Piece *TargetPiece;
    bool myTurn{};
    bool PiecePicked{};
    bool PiecePlacePicked{};
    int ArrayPositionTaken[9]{};
    int wins{};

public:
    Player(bool IsTeamOne);
    ~Player();
    std::vector<Piece *> getPieceVector() { return {
        &pieceVector[0],
        &pieceVector[1],
        &pieceVector[2],
    }; }

    void increaseWins()
    {
        wins = wins + 1;
    }

    int getWins()
    {
        return wins;
    }
    void resetArrayPositionTaken()
    {
        for (int i = 0; i < 9; i++)
        {
            ArrayPositionTaken[i] = 0;
        }
    }

    int *getPositionArray()
    {
        return ArrayPositionTaken;
    }

    Piece *setTargetPiece(Piece *Pjäs)
    {
        TargetPiece = Pjäs;
    };

    void changePositionArray(int Index)
    {
        if (ArrayPositionTaken[Index] == 0)
        {
            ArrayPositionTaken[Index] = 1;
        }
        else
        {
            ArrayPositionTaken[Index] = 0;
        }
    }
    Piece *GetTargetPiece()
    {
        return TargetPiece;
    }

    bool getMyTurn()
    {
        return myTurn;
    }

    void setIsMyTurn(bool isMyTurn)
    {
        myTurn = isMyTurn;
    }

    bool getPiecePicked()
    {
        return PiecePicked;
    }

    void setPiecePicked(bool IsPiecePicked)
    {
        PiecePicked = IsPiecePicked;
    }

    bool getPiecePlacePicked()
    {
        return PiecePlacePicked;
    }

    void setPiecePlacePicked(bool placePicked)
    {
        PiecePlacePicked = placePicked;
    }

    bool getIsTeamOne() { return IsTeamOne; }
};
#endif