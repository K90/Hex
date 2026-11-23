import std;
#include "vendor/raylib/raylib.h"

using std::vector;

constexpr int ScreenWidth{800};
constexpr int ScreenHeight{600};

class Hexagon {
    public:
        int sides{6};
        float radius{20.0f};

        void Draw(Vector2 pos, Color color) {
            DrawPoly(pos, sides, radius, 0, color);
        }
};

class Map {
    public:
        Vector2 mapSize{};
        float posX{};
        float posY{};

        Vector2 Init(vector<int> mapCoordinates) {

            int numColumns{};
            int highestNumCol{};
            int numRows{};

            for (std::size_t i{}; i < mapCoordinates.size(); ++i) {

                switch (mapCoordinates[i]) {
                    case 2:
                        ++numRows;
                        if (highestNumCol > numColumns) {
                            numColumns = highestNumCol;
                        }
                        highestNumCol = 0;
                        break;
                    default:
                        ++highestNumCol;
                        break;
                }
            }
            mapSize = {static_cast<float>(numRows), static_cast<float>(numColumns)};
            return mapSize;
        }

        void Draw(vector<int> mapCoordinates, float x, float y, Color color) {

            Hexagon slot; //empty space in map with hexagon border

            float paddingX{30};
            float paddingY{17};

            float offsetX{};
            float offsetY{};

            float numRows{mapSize.x};
            float numCols{mapSize.y};

            float normalizedX{x-(paddingX*numCols)+(paddingX/2)}; // offset with the centre of mapX
            float normalizedY{y-paddingY*(numRows/2)};            // offset with the centere of mapY
            int drawingRow{};

            for (std::size_t i{}; i < mapCoordinates.size(); ++i) {
                Vector2 drawPos{normalizedX+offsetX, normalizedY+offsetY};

                switch (mapCoordinates[i]) {
                    case 1:
                        offsetX += 60;
                        slot.Draw(drawPos, color);
                        break;
                    case 2:
                        offsetY += paddingY;
                        offsetX = paddingX;
                        ++drawingRow;
                        if (drawingRow % 2 == 0)
                            offsetX = 0;
                        break;
                    default:
                        offsetX += 60;
                        break;
                }
            }
        }

};

vector<int> mapSquare {
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 1, 2,
};

vector<int> mapHex {
0, 0, 1, 0, 0, 2,
0, 1, 1, 0, 0, 2,
0, 1, 1, 1, 0, 2,
1, 1, 1, 1, 0, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 0, 2,
1, 1, 0, 1, 1, 2,
1, 1, 1, 1, 0, 2,
1, 1, 1, 1, 1, 2,
1, 0, 0, 1, 0, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 0, 2,
1, 1, 1, 1, 1, 2,
1, 1, 1, 1, 0, 2,
0, 1, 1, 1, 0, 2,
0, 1, 1, 0, 0, 2,
0, 0, 1, 0, 0, 2,
};

int main(void) {

    InitWindow(ScreenWidth, ScreenHeight, "Hex");

    Map map;
    map.Init(mapHex);
    map.Init(mapSquare);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        map.Draw(mapHex, 400, 300, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
