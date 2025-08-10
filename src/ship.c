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
