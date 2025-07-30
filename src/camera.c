#include "camera.h"
#include "math.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>
void camera_update(input_state *state, Camera3D *camera) {
  // the camera is always targeted at the player position, therefore, it is the
  // camera *position* which gets updated. For now I like cyld, might make it
  // spherical. xyz is in game dev-ism order, xz is horizontal plane and y is
  // normal to that
  float_t phi = (state->mouse.x / (float_t)GetScreenWidth()) * PI * 2;
  float_t z = (state->mouse.y / (float_t)GetScreenHeight()) * 20.0f;
  camera->position.x = RHO * cosf(phi);
  camera->position.z = RHO * sinf(phi);
  printf("%f %f %f\n\r", phi, camera->position.x, camera->position.y);
  camera->position.y = z;
}
