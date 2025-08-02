#ifndef INPUT 
#define INPUT

#include "raylib.h"

//layer seperating game actions and physical player input

//key eventually becomes enum, and mapping gets handled in the input fns
//pressed eventually becomes a float to support controller
typedef struct{
  int key; 
  bool pressed;
} key_press;

typedef struct{
  //might want seperate toggle field?
  Vector2 view;
  key_press buttons[4];
} input_state;

void kb_input(input_state* input);

//for keyboard, the float is just 0 or 1
float get_action(input_state* input, int key);

#endif 
