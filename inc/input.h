#ifndef INPUT 
#define INPUT

#include "raylib.h"

typedef struct{
  int key; 
  bool pressed;
} key_press;

typedef struct{
  //should be something like view and 
  //actions or something general
  Vector2 mouse;
  key_press buttons[4];
}input_state;


void kb_input(input_state* input);


#endif 
