import std;
#include "vendor/raylib/raylib.h"

constexpr int ScreenWidth{800};
constexpr int ScreenHeight{600};
constexpr Vector2 ScreenCenter{ScreenWidth/2, ScreenHeight/2};

class Hexagon {
    public:
        int sides{6};
        float radius{20.0f};
        Color color{RAYWHITE};

        void Draw(Vector2 pos) {
            DrawPoly(pos, sides, radius, 0, color);
        }
};

int main(void) {
    InitWindow(ScreenWidth, ScreenHeight, "Hex");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        Hexagon h;
        h.Draw(ScreenCenter);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
