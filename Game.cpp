#include "Game.h"
#include <string>

std::string txt = "";

Game::Game(int i)
{
}

void Game::Reset()
{
    state = 0;
    Alive = true;
    Restart = false;
    Grid = 3;
    AllpiecesPlayed = false;
    playerTarget = {&playerVector[0]};
    playerVector[0].setIsMyTurn(true);
    board.resetArrayPositionTaken(); // samma på player
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            playerVector[i].getPieceVector()[j]->goToStart();
        }
        playerVector[i].resetArrayPositionTaken();
    }
}

void Game::Init()
{
    Player player1(true);
    Player player2(false);
    playerVector = {player1, player2};
    state = 0;
    Alive = true;
    Restart = false;
    Grid = 3;
    AllpiecesPlayed = false;
    playerTarget = {&playerVector[0]};
    playerVector[0].setIsMyTurn(true);
    board.resetArrayPositionTaken(); // samma på player
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            playerVector[i].getPieceVector()[j]->goToStart();
        }
        playerVector[i].resetArrayPositionTaken();
    }
}

void Game::Start()
{
    switch (state)
    {
    case 0:
    {
        DrawStart();
    }
    break;
    case 1:
    {
        DrawSettings();
    }
    break;
    case 2:
    {
        Draw();
    }
    break;
    case 3:
    {
        DrawPause();
    }
    break;
    }
}

void Game::Draw() // the game
{
    if (Alive)
    {

        board.DrawBoard(); // draw board

        switch (PlayerOneTurn)
        {
        case true:
            txt = "Player One's Turn";
            break;
        case false:
            txt = "Player Two's Turn";
            break;
        }
        const char *c = txt.c_str();
        DrawText(c, 450, 20, 22, YELLOW);

        std::string txtPoints1 = "P1 Wins: " + std::to_string(playerVector[0].getWins());
        std::string txtPoints2 = "P2 Wins: " + std::to_string(playerVector[1].getWins());
        std::string txtPause = "Pause(Q)";

        const char *d = txtPoints1.c_str();
        DrawText(d, 50, 20, 28, YELLOW);

        const char *dd = txtPoints2.c_str();
        const char *ww = txtPause.c_str();
        DrawText(dd, windowDimensions[1] + 175, 20, 28, YELLOW);
        DrawText(ww, windowDimensions[1] + 175, 50, 28, YELLOW);
        // Rita Upp Allt

        for (auto player : playerVector)
        {
            for (auto piece : player.getPieceVector())
            {
                if (player.getIsTeamOne())
                {
                    DrawCircle(piece->getX(), piece->getY(), Radius, PINK);
                }
                else
                {
                    DrawCircle(piece->getX(), piece->getY(), Radius, BLUE);
                }
            }
        }

        // kolla om spelet är pausat
        if (IsKeyDown(KEY_Q))
        {
            state = 3;
        }

        if (PlayerOneTurn)
        {
            playerTarget = &playerVector[0];
            playerTarget->setIsMyTurn(true);
            playerVector[1].setIsMyTurn(false);
        }
        else if (!PlayerOneTurn)
        {
            playerTarget = &playerVector[1];
            playerTarget->setIsMyTurn(true);
            playerVector[0].setIsMyTurn(false);
        }
        // while det är hans tur

        if (Turns == 6) // om alla bitar är ut spelade kan vi nu vlja fritt
        {
            for (int i = 0; i < 2; i++)
            {
                for (auto Piece : playerVector[i].getPieceVector())
                {
                    Piece->setCanBeChoosen(true);
                }
            }
        }

        if (playerTarget->getMyTurn()) //ändra piecePicked m.m.
        {
            if (!playerTarget->getPiecePicked())
            {
                // kolla om musen koliderar med någon av  dem

                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // om turns e mer än 6 ta bort den som vi nuddat förut från pos array
                {
                    for (auto piece : playerTarget->getPieceVector()) // kolla om musen nuddar någon
                    {
                        Vector2 circeln{piece->getX(), piece->getY()};
                        if (CheckCollisionCircles(GetMousePosition(), 1.f, circeln, Radius) && piece->getCanBeChoosen()) // om dom nuddar varandra och biten kan bli vald
                        {
                            playerTarget->setTargetPiece(piece);
                            playerTarget->setPiecePicked(true);
                            if (Turns < 6)
                            {
                                playerTarget->GetTargetPiece()->setCanBeChoosen(false); // Vi har valt en bit
                            }
                            break;
                        }
                    }
                    if (playerTarget->getPiecePicked() && Turns >= 6)
                    {
                        // vi ska ta bort den som markerad
                        positionTakenPointer = {board.getPositionTaken()}; // tar bord den från vårt kordinat system
                        for (int i = 0; i < 9; i++)
                        {
                            CollisionCircle = {static_cast<float>(PosPointer[i].x + 340.f), static_cast<float>(PosPointer[i].y + 160.f)};
                            Vector2 CollisionCircle2 = {playerTarget->GetTargetPiece()->getX(), playerTarget->GetTargetPiece()->getY()};
                            if (CheckCollisionCircles(CollisionCircle, 40, CollisionCircle2, 40) && positionTakenPointer[i])
                            {
                                positionTakenPointer[i] = 0;
                                playerTarget->changePositionArray(i);
                            }
                        }
                    }
                }
            }

            if (!playerTarget->getPiecePlacePicked() && playerTarget->getPiecePicked())
            {
                playerTarget->GetTargetPiece()->setX(GetMouseX());
                playerTarget->GetTargetPiece()->setY(GetMouseY());

                if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
                {
                    // kolla om vi kolliderar med någon av rutorna
                    positionTakenPointer = {board.getPositionTaken()};

                    for (int i = 0; i < 9; i++)
                    {
                        CollisionCircle = {static_cast<float>(PosPointer[i].x + 340.f), static_cast<float>(PosPointer[i].y + 160.f)};
                        if (CheckCollisionCircles(CollisionCircle, 40, GetMousePosition(), 5) && positionTakenPointer[i] < 1)
                        {
                            playerTarget->GetTargetPiece()->setX(CollisionCircle.x);
                            playerTarget->GetTargetPiece()->setY(CollisionCircle.y);
                            playerTarget->setPiecePlacePicked(true);
                            positionTakenPointer[i] = 1;
                            playerTarget->changePositionArray(i);
                            // mst ändra nått
                        }
                    }
                }
            }

            if (playerTarget->getPiecePicked() && playerTarget->getPiecePlacePicked())
            {
                if (Turns < 7)
                {
                    Turns++;
                }
                playerTarget->setPiecePicked(false);
                playerTarget->setPiecePlacePicked(false);
                playerTarget->setIsMyTurn(false);
                if (PlayerOneTurn)
                {
                    PlayerOneTurn = false;
                }
                else
                {
                    PlayerOneTurn = true;
                }
            }
        }

        // kolla om någon vunnit
        if (board.CheckWin(playerTarget)) // vi vann
        {
            if (playerTarget->getIsTeamOne())
            {
                playerOneWon = true;
                playerVector[0].increaseWins();
            }
            else
            {
                playerOneWon = false;
                playerVector[1].increaseWins();
            }
            Alive = false;
        }
        // Alive == falses
    }
    else if (!Alive)
    {

        std::string txt2 = "";
        std::string txt3 = "Press SPACE To Play Again...";
        if (playerOneWon)
        {
            txt2 = "Player One Is The Winner!";
        }
        else
        {
            txt2 = "Player Two Is The Winner!";
        }
        const char *c = txt2.c_str();
        DrawText(c, 300, 300, 38, YELLOW);

        const char *b = txt3.c_str();
        DrawText(b, 350, 500, 28, YELLOW);

        if (IsKeyPressed(KEY_SPACE))
        {
            Alive = true;
            Reset();
        }
    }
}

// draw States

void Game::DrawPause() // pause screen
{
    txt = "Press Space To Resume..";
    const char *c = txt.c_str();
    DrawText(c, 300, 350, 44, YELLOW);
    if (IsKeyDown(KEY_SPACE))
    {
        state = 2;
    }
};
void Game::DrawStart() // start screen
{
    txt = "Press Space To Start..";
    const char *c = txt.c_str();
    DrawText(c, 300, 350, 44, YELLOW);
    if (IsKeyDown(KEY_SPACE))
    {
        state = 2; // settings
    }
};
void Game::DrawSettings() // setting page
{
    txt = "Settings";
    const char *c = txt.c_str();
    DrawText(c, 350, 400, 2, BLACK);
};

Game::~Game()
{
}