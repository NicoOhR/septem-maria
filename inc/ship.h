#ifndef SHIP
#define SHIP

#include "input.h"
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>

#define SPEED 0.0005

typedef struct{
  Vector3 position;
  Quaternion orientation;
}ship_state ;

void ship_update(input_state *input, ship_state* ship);

void ship_draw(ship_state* ship, Model *model);

#endif // !SHIP
