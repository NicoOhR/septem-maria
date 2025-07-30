#include "input.h"
#include <raylib.h>
#include <stdio.h>

void kb_input(input_state *input) {
  input->mouse = GetMousePosition();
  for (int i = 0; i < 4; i++) {
    input->buttons[i].pressed = IsKeyDown(input->buttons[i].key);
  }
}
