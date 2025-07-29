#include "input.h"
#include <raylib.h>
#include <stdio.h>

void kb_input(input_state *input) {
  input->mouse = GetMousePosition();
  printf("%f %f\n", input->mouse.x, input->mouse.y);
  for (int i = 0; i < 4; i++) {
    input->buttons[i].pressed = IsKeyDown(input->buttons[i].key);
    printf("%d %d \r\n", i, input->buttons[i].pressed);
  }
}
