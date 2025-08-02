#include "camera.h"
#include "input.h"
#include "raylib.h"
#include "ship.h"
#include <stdio.h>

int main(void) {
  InitWindow(800, 450, "raylib [core] example - basic window");
  Camera camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  input_state input = {.view = (Vector2){0.0f, 0.0f},
                       .buttons = {
                           {.key = KEY_W, .pressed = false},
                           {.key = KEY_A, .pressed = false},
                           {.key = KEY_S, .pressed = false},
                           {.key = KEY_D, .pressed = false},
                       }};
  ship_state ship = {
      .position = (Vector3){0},
      .heading = (Quaternion){0},

  };
  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_CUSTOM);

    kb_input(&input);
    camera_update(&input, &ship, &camera);
    ship_update(&input, &ship);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    DrawGrid(20, 1.0f);
    DrawCube(ship.position, 1.0f, 1.0f, 1.0f, BLACK);
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
