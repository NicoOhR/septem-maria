#include "ship.h"
#include "input.h"
#include <raylib.h>
#include <stdio.h>

void ship_update(input_state *input, ship_state *ship) {
  ship->position.x = ship->position.x + (SPEED * get_action(input, THROTTLE));

  ship->position.z = ship->position.z + (SPEED * get_action(input, STEER_LEFT));
  ship->position.z =
      ship->position.z - (SPEED * get_action(input, STEER_RIGHT));
}
