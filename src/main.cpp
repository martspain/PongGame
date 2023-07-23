#include "Pong.h"
// #include <SDL2/SDL.h>

int main (int argc, char *argv[]) {
  Pong pong = Pong("pong", 800, 600);
  pong.run();
  return 0;
};
