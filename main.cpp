import std;
#include "vendor/raylib/raylib.h"

constexpr int ScreenWidth{800};
constexpr int ScreenHeight{600};

class Hexagon {
    public:
        int sides{6};
        float radius{20.0f};
        Color color{RAYWHITE};

        void Draw(Vector2 pos) {
            DrawPolyLines(pos, sides, radius, 0, color);
        }
};

void DrawMap(std::vector<int> MapCoords);

int main(void) {

    InitWindow(ScreenWidth, ScreenHeight, "Hex");

    Vector2 ScreenCenter{ScreenWidth / 2, ScreenHeight / 2};
    int SCX {static_cast<int>(ScreenCenter.x)};
    int SCY{static_cast<int>(ScreenCenter.y)};

    std::vector<int> MapCoords {1, 1, 0, 1, 1};

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        DrawMap(MapCoords);

        Hexagon h;
        h.Draw(ScreenCenter);
        DrawLine(SCX, SCY-18, SCX, SCY+18, VIOLET);
        DrawLine(SCX-20, SCY, SCX+20, SCY, VIOLET);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawMap(std::vector<int> MapCoords) {

    float padding_x{};
    Hexagon s;
    for (std::size_t i{}; i <= MapCoords.size(); ++i) {

        padding_x += 60;
        Vector2 padding{0+padding_x, 20};

        s.Draw(padding);
    }
}
