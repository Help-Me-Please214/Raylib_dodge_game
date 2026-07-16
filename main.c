#include "raylib.h"

int main(void)
{
    // Set up the window
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Dodge Game");
    SetTargetFPS(60);

    // Player setup
    Rectangle player = { 375, 540, 50, 50 };   // x, y, width, height
    float playerSpeed = 6.0f;

    while (!WindowShouldClose())
    {
        // Update player position based on input
        if (IsKeyDown(KEY_LEFT))  player.x -= playerSpeed;
        if (IsKeyDown(KEY_RIGHT)) player.x += playerSpeed;

        // Keeps player on screen
        if (player.x < 0) player.x = 0;
        if (player.x > screenWidth - player.width) player.x = screenWidth - player.width;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(player, BLUE);
        DrawText("Move with LEFT/RIGHT arrows", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}