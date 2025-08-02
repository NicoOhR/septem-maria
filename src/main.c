#include "camera.h"
#include "input.h"
#include "raylib.h"
#include "ship.h"
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

  ship_state ship = {
      .position = (Vector3){1.0f, 1.0f, 1.0f},
      .heading = (Quaternion){0},
  };

  Model model = LoadModel("./res/boat/12219_boat_v2_L2.obj");
  Texture2D texture = LoadTexture("./res/boat/boat_body_diffuse.jpg");
  model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
  BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);
  // TODO figure out texture

  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_CUSTOM);

    kb_input(&input);
    camera_update(&input, &ship, &camera);
    ship_update(&input, &ship);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    DrawGrid(20, 1.0f);
    DrawModel(model, (Vector3){0.0f, 0.0f, 0.0f}, 0.005f, DARKGRAY);
    DrawCube(ship.position, 1.0f, 1.0f, 1.0f, BLACK);
    EndMode3D();
    EndDrawing();
  }
  UnloadModel(model);
  CloseWindow();

  return 0;
}
