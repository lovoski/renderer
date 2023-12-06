#include "pixie.h"
#include "font.h"
#include "imgui.h"
#include "buffer.h"

#include <iostream>

const int width = 1600;
const int height = 900;

int main() {
  Pixie::Font font;
  font.LoadDefaultFont();
  Pixie::Window window;
  if (!window.Open("renderer", width, height)) {
    printf("error creating window\n");
    return -1;
  }
  Buffer buffer(window.GetPixels(), width, height);
  while (!window.HasKeyGoneDown(Pixie::Key_Escape)) {
    buffer.clear();
    Pixie::ImGui::Begin(&window, &font);
    Pixie::ImGui::Label("hello from pixie window", 700, 450, MAKE_RGB(255, 255, 255));
    Pixie::ImGui::End();
    if (!window.Update()) {
      printf("error updating window\n");
      break;
    }
  }
  window.Close();
  return 0;
}