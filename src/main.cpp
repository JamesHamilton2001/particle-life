#include "ParticleLife.h"
#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>



static int frameRate = 60;
Vector2 screenSize = { 512, 512 };

Camera2D camera;
<<<<<<< HEAD
float zoomIncrement = 0.4f;
=======
float zoomIncrement = 0.01f;
>>>>>>> 9e369970fa2b7dd52533fdd4db73eb7f9435e121

float radius = 2.0f;
float innerRange = 0.3f;
float outerRange = 1.0f;
<<<<<<< HEAD
float resistance = 0.15f;

int count = 1024;
int size = 24;
=======
float resistance = 0.8f;

int count = 4;
int size = 4;
>>>>>>> 9e369970fa2b7dd52533fdd4db73eb7f9435e121
int bound = size / 2;
float cellSize = outerRange * 2.0f;

ParticleLife particleLife(count, size, innerRange, outerRange, resistance);


int main()
{
    InitWindow(screenSize.x, screenSize.y, "Particle Life");
    SetTargetFPS(frameRate);

    camera.offset = { screenSize.x / 2.0f, screenSize.y / 2.0f };
    camera.target = { 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 scaledInvMouseDelta = Vector2Scale(GetMouseDelta(), -1.0f / camera.zoom);
            camera.target = Vector2Add(camera.target, scaledInvMouseDelta);
        }
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            camera.target = GetScreenToWorld2D(camera.offset, camera);
            camera.zoom += (wheel * zoomIncrement);
            if (camera.zoom < zoomIncrement)
                camera.zoom = zoomIncrement;
        }

        particleLife.update();

        BeginDrawing();
            ClearBackground(DARKGRAY);
            BeginMode2D(camera);

                // for (int i = -bound; i <= bound; i++) {
                //     DrawLine(i * cellSize, -bound * cellSize, i * cellSize, bound * cellSize, GRAY);
                //     DrawLine(-bound * cellSize, i * cellSize, bound * cellSize, i * cellSize, GRAY);
                // }

                particleLife.draw();

            EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}