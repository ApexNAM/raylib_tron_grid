#include "raylib.h"

class Grid
{
private:
    float t = 0.0f;
public:
    Grid() { }
    ~Grid() { }

    void Draw()
    {
        const int screenWidth = 816;
        const int screenHeight = 624;

        int w = screenWidth - 1;
        int n = 64;

        t += 10.75f;
        for (int i = 0; i <= n; i++)
        {
            int z = (i * n + (int)t % n) + 1;
            int y = (w * n) / z + 32;
            DrawLine(0, y, w, y, BROWN);

            float v = i + n / (float)n - n / 2.0f;
            DrawLine(v * (screenWidth / 20) + (screenWidth / 2), (screenHeight / 9), v * (screenWidth / 0.75f) + (screenWidth / 2), w, BROWN);
        }
    }
};

int main()
{
    const int screenWidth = 816;
    const int screenHeight = 624;

    InitWindow(screenWidth, screenHeight, "Horizon Grid");

    SetTargetFPS(60);

    Grid grid;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        grid.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
