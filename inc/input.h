#ifndef INPUT 
#define INPUT

#include "raylib.h"

//layer seperating game actions and physical player input

typedef enum {
  THROTTLE,
  STEER_LEFT,
  STEER_RIGHT,
  REVERSE
}action;

//I imagine key becomes a union, depending on which control scheme is chosen
typedef struct {
  action action;
  int key;
}binding;

typedef struct{
  action action; 
  float value;
} action_value;

typedef struct{
  Vector2 view;
  action_value actions[4];
  binding bindings[4];
} input_state;

void kb_input(input_state* input);

//for keyboard, the float is just 0 or 1
float get_action(input_state* input, action action);

#endif 
