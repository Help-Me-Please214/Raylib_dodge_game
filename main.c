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

    // Enemy setup
    Rectangle enemy = { 0, 0, 50, 50 };   // x, y, width, height
    float enemySpeed = 4.0f;

    //Main game loop

    while (!WindowShouldClose())
    {
        // Update player position based on input
        if (IsKeyDown(KEY_LEFT))  player.x -= playerSpeed;
        if (IsKeyDown(KEY_RIGHT)) player.x += playerSpeed;

        // Keeps player on screen
        if (player.x < 0) player.x = 0;
        if (player.x > screenWidth - player.width) player.x = screenWidth - player.width;
        
        // Update enemy position
        enemy.y += enemySpeed;

        // Reset enemy position if it goes off screen
        if (enemy.y > screenHeight)
        {
            enemy.y = 0;
            enemy.x = GetRandomValue(0, screenWidth - enemy.width);
        }

        //collision detection
        if (CheckCollisionRecs(player, enemy))
        {
            DrawText("HIT", player.x + 8, player.y - 20, 20, RED);
        }
    
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(player, BLUE);
        DrawRectangleRec(enemy, RED);
        DrawText("Move with LEFT/RIGHT arrows, avoid the red blocks!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}