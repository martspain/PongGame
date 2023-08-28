#include <iostream>
// #include <print.h>
#include "Game.h"

Game::Game(const char* name, int width, int height) 
  : screen_width(width), screen_height(height) {
  print("Game Constructor");
  SDL_SetMainReady();
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    // Variable init
    isRunning = true;
    lastFPSUpdate = 0;
    frameStartTimestamp = 0;
    frameEndTimestamp = 0;
    frameCountPerSecond = 0;
    FPS = 0;
    int maxFPS = 120;
    frameDuration = (1.0f/maxFPS) * 1000.0f;
    frameCount = 0;
  } else {
    isRunning = false;
  }

}
Game::~Game() {
  print("Game Destructor");

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::setScene(Scene* newScene) {
  currentScene = newScene;
  currentScene->setup();
}

// void Game::setup() {
//   print("Game Setup");
// }

void Game::frameStart() {
  print("# --- --- Frame", frameCount ,"--- --- #");
  frameStartTimestamp = SDL_GetTicks();

  if (frameEndTimestamp > 0) {
    // frameEndTimestamp is previous frame's time
    dT = (frameStartTimestamp - frameEndTimestamp) / 1000.0f;
  } else {
    dT = 0;
  }
}

void Game::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
    }
  }
}

void Game::frameEnd() {
  frameEndTimestamp = SDL_GetTicks();

  float actualFrameDuration = frameEndTimestamp - frameStartTimestamp;

  if (actualFrameDuration < frameDuration) {
    SDL_Delay(frameDuration - actualFrameDuration);
  }

  // FPS Calculation
  frameCount++;
  frameCountPerSecond++;
  Uint32 currentTime = SDL_GetTicks();
  Uint32 timeElapsed = currentTime - lastFPSUpdate;

  if (timeElapsed > 1000) {
    FPS = frameCountPerSecond / (timeElapsed / 1000);
    lastFPSUpdate = currentTime;
    frameCountPerSecond = 0;
  }
  print("FPS -> ", FPS);
  print("=============================");
}

void Game::update() {
  print("Update");
}

void Game::render() {
  print("Render");

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
}

bool Game::running() {
  return isRunning;
}

void Game::run() {
  while (running()) {
    frameStart();
    handleEvents();

    update();
    render();

    frameEnd();
  }
}