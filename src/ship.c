#include "ship.h"
#include "input.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

void ship_update(input_state *input, ship_state *ship) {
  Vector3 axis;
  float angle;

  Vector3 translation = Vector3Scale(
      Vector3RotateByQuaternion((Vector3){1, 0, 0}, ship->orientation),
      (SPEED * get_action(input, THROTTLE)));
  ship->position = Vector3Add(ship->position, translation);

  QuaternionToAxisAngle(ship->orientation, &axis, &angle);
  Vector3 up = Vector3RotateByQuaternion((Vector3){0, 1, 0}, ship->orientation);
  double theta =
      SPEED * (-get_action(input, STEER_LEFT) + get_action(input, STEER_RIGHT));
  Quaternion delta = QuaternionFromAxisAngle(up, theta);
  ship->orientation = QuaternionMultiply(delta, ship->orientation);
}

void ship_draw(ship_state *ship, Model *model) {
  Vector3 ax;
  float ang;
  QuaternionToAxisAngle(ship->orientation, &ax, &ang);
  DrawModelEx(*model, ship->position, ax, RAD2DEG * ang,
              (Vector3){1.0f, 1.0f, 1.0f}, DARKGRAY);
#ifndef NDEBUG
  const float L = 10.0f;
  Vector3 right =
      Vector3RotateByQuaternion((Vector3){1, 0, 0}, ship->orientation);
  Vector3 up = Vector3RotateByQuaternion((Vector3){0, 1, 0}, ship->orientation);
  Vector3 fwd =
      Vector3RotateByQuaternion((Vector3){0, 0, 1}, ship->orientation);

  DrawLine3D(ship->position, Vector3Add(ship->position, Vector3Scale(right, L)),
             (Color){230, 41, 55, 255});
  DrawLine3D(ship->position, Vector3Add(ship->position, Vector3Scale(up, L)),
             GREEN);
  DrawLine3D(ship->position, Vector3Add(ship->position, Vector3Scale(fwd, L)),
             BLUE);
#endif
}
