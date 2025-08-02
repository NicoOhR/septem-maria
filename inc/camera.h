#ifndef CAMERA
#define CAMERA
#include "input.h"
#include "ship.h"
#include <raylib.h>
#define RHO 10.0f
void camera_update(input_state* input, ship_state* ship, Camera3D* camera);

#endif // !CAMERA
