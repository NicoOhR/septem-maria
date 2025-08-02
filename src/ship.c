#include "ship.h"
#include "input.h"
#include <raylib.h>
#include <stdio.h>

void ship_update(input_state *input, ship_state *ship) {
  ship->position.x = ship->position.x + (SPEED * get_action(input, THROTTLE));
  // what I want STEER to do is change the HEADING of the body, not the position
  // position should only ever be updated by THROTTLE or REVERSE
  ship->position.z = ship->position.z + (SPEED * get_action(input, STEER_LEFT));
  ship->position.z =
      ship->position.z - (SPEED * get_action(input, STEER_RIGHT));
}
