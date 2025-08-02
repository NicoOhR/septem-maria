#include "input.h"
#include <raylib.h>
#include <stdio.h>

void kb_input(input_state *input) {
  // for all actions,
  // check what button that action is bound to
  // isKeyDown and cast to float
  //
  // shitty O(n^2) impl, simple fix after hashmaps are added
  input->view = GetMousePosition();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (input->actions[i].action == input->bindings[j].action) {
        input->actions[i].value = IsKeyDown(input->bindings[j].key);
      }
    }
  }
}

float get_action(input_state *input, action action) {
  for (int i = 0; i < 4; i++) {
    if (input->actions[i].action == action) {
      return input->actions[i].value;
    }
  };
  return -1.0f;
}
