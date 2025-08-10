#include "camera.h"
#include "input.h"
#include "raylib.h"
#include "ship.h"
#include <raymath.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  InitWindow(800, 450, "Septem Maria");

  Camera camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  input_state input = {
      .view = (Vector2){0.0f, 0.0f},
      .actions =
          {
              {THROTTLE, 0.0f},
              {STEER_LEFT, 0.0f},
              {STEER_RIGHT, 0.0f},
              {REVERSE, 0.0f},
          },
      .bindings =
          {
              {.action = THROTTLE, .key = KEY_W},
              {.action = STEER_LEFT, .key = KEY_D},
              {.action = STEER_RIGHT, .key = KEY_A},
              {.action = REVERSE, .key = KEY_S},
          },
  };

  ship_state ship = {.position = (Vector3){0.0f, 0.0f, 0.0f},
                     .orientation = (Quaternion){0.0f, 0.0f, 0.0f, 1.0f}};

  Model model = LoadModel("./res/boat/fixed.obj");
  BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_CUSTOM);

    kb_input(&input);
    camera_update(&input, &ship, &camera);
    ship_update(&input, &ship);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    DrawGrid(20, 1.0f);
    ship_draw(&ship, &model);
    EndMode3D();
    EndDrawing();
  }
  UnloadModel(model);
  CloseWindow();

  return 0;
}
