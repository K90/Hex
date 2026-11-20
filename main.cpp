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

void DrawMap(std::vector<int> mapCoords, float x, float y);

int main(void) {

    InitWindow(ScreenWidth, ScreenHeight, "Hex");

    Vector2 ScreenCenter{ScreenWidth / 2, ScreenHeight / 2};

    std::vector<int> map1 {1, 1, 1, 1, 1, 2,
                                1, 1, 1, 1, 1, 2,
                                1, 1, 1, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 0, 1, 1, 2,
                                1, 1, 1, 1, 1, 2,
                                1, 1, 1, 1, 1, 2,
                                1, 1, 1, 1, 1, 2,};

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        DrawMap(map1, 400, 300);

        Hexagon h;
        h.Draw(ScreenCenter);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawMap(std::vector<int> mapCoords, float x, float y) {

    Hexagon slot;
    float offsetX{30};
    float offsetY{17};

    float paddingX{};
    float paddingY{};

    int numRows{};
//    int numColumns{};

    for (std::size_t i{}; i < mapCoords.size(); ++i) {

        paddingX += 60;
        Vector2 drawPos{x+paddingX, y+paddingY};

//        switch (mapCoords[i]) {
//            case '1':

//                break;
//        }

        if (mapCoords[i] == 1)
            slot.Draw(drawPos);

        if (mapCoords[i] == 2) {
            paddingX = offsetX;
            paddingY += offsetY;
            ++numRows;
        if (numRows % 2 == 0)
                paddingX = 0;
        }
    }
}
