import std;
#include "vendor/raylib/raylib.h"

int main(void) {

    InitWindow(800, 600, "raylib_skeleton");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
