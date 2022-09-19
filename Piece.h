#ifndef MYCLASS_H // #include guards
#define MYCLASS_H
class Piece
{
private:
    int x{};
    int y{};
    bool PickedUp{};
    int StartPositionX{};
    int StartPositionY{};
    bool canbeChoosen{true};

public:
    Piece(int startX, int startY);
    ~Piece();

    void setX(int _x) { this->x = _x; }
    int getX() { return this->x; }

    void setY(int _y) { this->y = _y; }
    int getY() { return this->y; }

    bool getCanBeChoosen()
    {
        return canbeChoosen;
    }

    void setCanBeChoosen(bool canBe)
    {
        canbeChoosen = canBe;
    }
    void goToStart();
};

#endif // MYCLASS_H_