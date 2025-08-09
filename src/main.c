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

  double theta = -PI / 2.0;
  Vector3 u = {1.0f, 0.0f, 0.0f};
  Quaternion upright_transformation;
  upright_transformation = QuaternionFromAxisAngle(u, (float)theta);
  theta = PI;
  Vector3 v = {0.0f, 1.0f, 0.0f};
  Quaternion turn_around = QuaternionFromAxisAngle(v, (float)theta);
  Quaternion comp = QuaternionMultiply(turn_around, upright_transformation);
  ship_state ship = {
      .position = (Vector3){0.0f, 0.0f, 0.0f},
      .orientation = QuaternionNormalize(comp),
  };

  Model model = LoadModel("./res/boat/12219_boat_v2_L2.obj");
  Texture2D texture = LoadTexture("./res/boat/boat_body_diffuse.jpg");
  model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
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
    float ang;
    Vector3 ax;
    QuaternionToAxisAngle(ship.orientation, &ax, &ang);
    DrawModelEx(model, ship.position, ax, RAD2DEG * ang,
                (Vector3){0.005f, 0.005f, 0.005f}, DARKGRAY);
    const float L = 5.0f;
    Vector3 right =
        Vector3RotateByQuaternion((Vector3){1, 0, 0}, ship.orientation);
    Vector3 up =
        Vector3RotateByQuaternion((Vector3){0, 1, 0}, ship.orientation);
    Vector3 fwd =
        Vector3RotateByQuaternion((Vector3){0, 0, 1}, ship.orientation);
    DrawLine3D(ship.position, Vector3Add(ship.position, Vector3Scale(right, L)),
               RED);
    DrawLine3D(ship.position, Vector3Add(ship.position, Vector3Scale(up, L)),
               GREEN);
    DrawLine3D(ship.position, Vector3Add(ship.position, Vector3Scale(fwd, L)),
               BLUE);
    EndMode3D();
    EndDrawing();
  }
  UnloadModel(model);
  CloseWindow();

  return 0;
}
