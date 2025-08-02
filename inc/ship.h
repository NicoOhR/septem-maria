#ifndef SHIP
#define SHIP

#include "input.h"
#include <raylib.h>
#include <raymath.h>

#define SPEED 0.0005

typedef struct{
  Vector3 position;
  Quaternion heading;
}ship_state ;

void ship_update(input_state *input, ship_state* ship);

#endif // !SHIP
