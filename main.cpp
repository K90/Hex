import std;
#include "vendor/raylib/raylib.h"

using std::pair, std::vector;

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

pair<float, float> MapInit(vector<int> mapCoords);
void DrawMap(vector<int> mapCoords, pair<float, float> mapSize, float x, float y);

vector<int> map1 {1, 1, 1, 1, 1, 2,
                       1, 1, 1, 1, 1, 2,
                       1, 1, 1, 1, 1, 2,};

int main(void) {

    InitWindow(ScreenWidth, ScreenHeight, "Hex");
    std::pair<float, float> mapSize = MapInit(map1);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        DrawMap(map1, mapSize, 0, 0);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

pair<float, float> MapInit(vector<int> mapCoords) {

    int numColumns{};
    int highestNumCol{};
    int numRows{};

    for (std::size_t i{}; i < mapCoords.size(); ++i) {

        if (mapCoords[i] != 2)
            ++highestNumCol;
        if (mapCoords[i] == 2) {
            ++numRows;
            if (highestNumCol > numColumns) {
                numColumns = highestNumCol;
            }
            highestNumCol = 0;
        }
    }
    return std::make_pair(numRows, numColumns);
}

void DrawMap(vector<int> mapCoords, pair<float, float> mapSize, float x, float y) {

    Hexagon slot;

    float paddingX{30};
    float paddingY{17};

    float offsetX{};
    float offsetY{};

    float centerX{x-(mapSize.first*paddingX/2)};
    float centerY{y-(mapSize.second*paddingY/2)};

    DrawCircle(static_cast<int>(x), static_cast<int>(y), 10, VIOLET);

    int numRows{};

    for (std::size_t i{}; i < mapCoords.size(); ++i) {

        offsetX += 60;
        Vector2 drawPos{x+offsetX, y+offsetY};

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
                break;
        }
    }
}
