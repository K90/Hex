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

bool InitMap(std::vector<int> mapCoords, bool initState);
void DrawMap(std::vector<int> mapCoords, float x, float y);

std::vector<int> map1 {1, 1, 1, 1, 1, 2,
                       1, 1, 1, 1, 1, 2,
                       1, 1, 1, 1, 1, 2,};
bool mapInit{false};

int main(void) {

    InitWindow(ScreenWidth, ScreenHeight, "Hex");
    InitMap(map1, mapInit);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        DrawMap(map1, 400, 300);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawMap(std::vector<int> mapCoords, float x, float y) {

    Hexagon slot;
    float paddingX{30};
    float paddingY{17};
    float offsetX{};
    float offsetY{};
    int numRows{};

    for (std::size_t i{}; i < mapCoords.size(); ++i) {

        offsetX += 60;
        Vector2 drawPos{x + offsetX, y + offsetY};

        switch (mapCoords[i]) {
            case 1:
                slot.Draw(drawPos); //render a slot
                break;
            case 2:
                offsetY += paddingY; //new row
                offsetX = paddingX; // back to start
                ++numRows;
                if (numRows % 2 == 0) //
                    offsetX = 0;
        }
    }
}

bool MapInit(std::vector<int> mapCoords, bool initState) {

    int numRows{};
    int numColumns{};
    int highestNumRows{};
    int highestNumCol{};

    for (std::size_t i{}; i < mapCoords.size() && !initState; ++i) {
        switch (mapCoords[i]) {
            case 1:
                ++numColumns;
                if(numColumns == 0 || numColumns > highestNumCol)
                    numColumns = highestNumCol;
                break;
            case 2:
                ++numRows;
                if (numRows == 0 || numRows > highestNumRows)
                    numRows = highestNumRows;
        }
    }
    initState = true;
    return initState;
}
