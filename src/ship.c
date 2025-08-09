#include "ship.h"
#include "input.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

void ship_update(input_state *input, ship_state *ship) {
  ship->position.x = ship->position.x + (SPEED * get_action(input, THROTTLE));
  Vector3 axis;
  float angle;
  QuaternionToAxisAngle(ship->orientation, &axis, &angle);
  Vector3 up = Vector3RotateByQuaternion((Vector3){0, 0, 1}, ship->orientation);
  double theta =
      SPEED * (get_action(input, STEER_LEFT) - get_action(input, STEER_RIGHT));
  Quaternion delta = QuaternionFromAxisAngle(up, theta);
  ship->orientation = QuaternionMultiply(delta, ship->orientation);
}
