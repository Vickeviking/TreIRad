#include "raylib.h"
#include "Game.h"

int main()
{
    Game game(2);
    game.Init();
    int width = game.getWindowDimensions()[0];
    int height = game.getWindowDimensions()[1];
    InitWindow(width, height, "Tre i Rad");
    Texture2D text = LoadTexture("Texture/Bradet.png");
    Texture2D Tile = LoadTexture("Texture/Tile.png");
    Texture Background = LoadTexture("Texture/Background.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        if (game.getAlive())
        {
            ClearBackground(WHITE);
            if (game.getState() == 2)
            {
                DrawTexture(Background, 0, 0, WHITE);
                DrawTexture(text, game.getboard().getBoardx(), game.getboard().getBoardy(), WHITE); // detta texture ifall state 2

                for (int i = 0; i < 9; i++)
                {
                    DrawTexture(Tile, game.getboard().getBoardx() + game.getboard().getPossitionArray()[i].x, game.getboard().getBoardy() + game.getboard().getPossitionArray()[i].y, WHITE);
                }
            }
            else if (game.getState() == 0)
            {
                DrawTexture(Background, 0, 0, WHITE);
            }
            else if (game.getState() == 3)
            {
                DrawTexture(Background, 0, 0, WHITE);
            }
        }
        else
        {
            DrawTexture(Background, 0, 0, WHITE);
        }

        game.Start();

        EndDrawing();
    }
    UnloadTexture(text); // unload texture
    UnloadTexture(Tile);
    UnloadTexture(Background);
    CloseWindow();
}