#include "camera.h"
#include "math.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>

void camera_update(input_state *input, ship_state *ship, Camera3D *camera) {
  // the camera is always targeted at the player position, therefore, it is the
  // camera *position* which gets updated. For now I like cyld, might make it
  // spherical. Additional linear translation to keep the player centered
  //
  // xyz is in game dev-ism order, xz is horizontal plane and y is
  // normal to that

  float_t phi = (input->view.x / (float_t)GetScreenWidth()) * PI * 2;
  float_t z = (input->view.y / (float_t)GetScreenHeight()) * 20.0f;
  camera->position.x = RHO * cosf(phi) + ship->position.x;
  camera->position.z = RHO * sinf(phi) + ship->position.z;
  camera->position.y = z + ship->position.y;
  camera->target = ship->position;
}
