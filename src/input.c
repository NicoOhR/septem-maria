#include "input.h"
#include <raylib.h>
#include <stdio.h>

void kb_input(input_state *input) {
  input->view = GetMousePosition();
  for (int i = 0; i < 4; i++) {
    input->buttons[i].pressed = IsKeyDown(input->buttons[i].key);
  }
}

float get_action(input_state *input, int key) {
  // will need to spend some time implementing a proper hash map
  // ik there's that single header lib that can be used
  for (int i = 0; i < sizeof(input->buttons); i++) {
    if (input->buttons[i].key == key) {
      return (float)input->buttons[i].pressed;
    }
  };
}
