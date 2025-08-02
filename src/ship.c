#include "ship.h"
#include "input.h"
#include <raylib.h>

void ship_update(input_state *input, ship_state *ship) {
  ship->position.x = ship->position.x + (SPEED * get_action(input, KEY_W));
  ship->position.z = ship->position.z + (SPEED * get_action(input, KEY_A));
  ship->position.z = ship->position.z - (SPEED * get_action(input, KEY_D));
}
