#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int spriteWidth = 128;
const int spriteHeight = 128;
const int numFrames = 6;
const int numRows = 1;

int currentFrame = 0;
int currentRow = 0;
float frameTimer = 0.0f;
float frameSpeed = 0.1f;

Rectangle sourceRect;
Rectangle destRect;

void UpdateAnimation()
{
    frameTimer += GetFrameTime();

    if (frameTimer >= frameSpeed)
    {
        frameTimer = 0.0f;
        currentFrame++;

        if (currentFrame >= numFrames)
        {
            currentFrame = 0;
        }
    }

    sourceRect.x = currentFrame * spriteWidth;
    sourceRect.y = currentRow * spriteHeight;
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Animation Sprite Example");

    // Load animation sprite sheet
    Texture2D spriteSheet = LoadTexture("animation.png");

    // Set up source and destination rectangles
    sourceRect = { 0, 0, spriteWidth, spriteHeight };
    destRect = { screenWidth / 2 - spriteWidth / 2, screenHeight / 2 - spriteHeight / 2, spriteWidth, spriteHeight };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateAnimation();

        if (IsKeyPressed(KEY_W))
            currentRow = 0;
        else if (IsKeyPressed(KEY_S))
            currentRow = 1;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw current frame of animation
        DrawTexturePro(spriteSheet, sourceRect, destRect, { 0,0 }, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(spriteSheet);
    CloseWindow();

    return 0;
}
