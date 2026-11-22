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

                if (mapCoordinates[i] != 2)
                    ++highestNumCol;
                if (mapCoordinates[i] == 2) {
                    ++numRows;
                    if (highestNumCol > numColumns) {
                        numColumns = highestNumCol;
                    }
                    highestNumCol = 0;
                }
            }
            mapSize = {static_cast<float>(numRows), static_cast<float>(numColumns)};
            std::cout << "R: " << numRows << '\t' << "C: " << numColumns << '\n';
            return mapSize;
        }

        void Draw(vector<int> mapCoordinates, float x, float y) {

            Hexagon slot; //empty space in map

            float paddingX{30};
            float paddingY{17};

            float offsetX{};
            float offsetY{};
//temp
            std::cout << "x: " << mapSize.x << '\t' << mapSize.y << "y: " << '\n';

            int debug_paddingX{static_cast<int>(paddingX)};
            int debug_paddingY{static_cast<int>(paddingY)};
            int debug_mapSizeX{static_cast<int>(mapSize.x)};
            int debug_mapSizeY{static_cast<int>(mapSize.y)};

            DrawCircle(
                (static_cast<int>(x)+debug_paddingX*debug_mapSizeY-(debug_paddingX/2)),
                (static_cast<int>(y)+debug_paddingY*(debug_mapSizeX/2)), 10,
                VIOLET);
          //   DrawCircle(10, 10, 10, VIOLET);

            int numRows{};

            for (std::size_t i{}; i < mapCoordinates.size(); ++i) {

                Vector2 drawPos{x+offsetX, y+offsetY};

                switch (mapCoordinates[i]) {
                    case 1:
                        offsetX += 60;
                        slot.Draw(drawPos);
                        break;
                    case 2:
                        offsetY += paddingY;
                        offsetX = paddingX;
                        ++numRows;
                        if (numRows % 2 == 0)
                            offsetX = 0;
                        break;
                }
            }
        }

};

vector<int> map1 {1, 1, 1, 1, 1, 2,
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
                  1, 1, 1, 1, 1, 2,};

int main(void) {

    Map mapone;

    InitWindow(ScreenWidth, ScreenHeight, "Hex");
    mapone.Init(map1);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        mapone.Draw(map1, 400, 300);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
