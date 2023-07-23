#pragma once
#include <print.h>
#include <SDL2/SDL.h>

class Game {
  public:
    Game(const char* name, int width, int height);
    ~Game();

    virtual void setup();
    void frameStart();
    void frameEnd();
    virtual void handleEvents();
    virtual void update();
    virtual void render();
    bool running();

    void run();
  
  protected:
    int width;
    int height;
    bool isRunning;
    int screen_width;
    int screen_height;

    SDL_Window* window;
    SDL_Renderer* renderer;

    // FPS Counter
    int FPS;
    int frameCount;
    int frameCountPerSecond;
    Uint32 frameStartTimestamp;
    Uint32 frameEndTimestamp;
    Uint32 lastFPSUpdate;
    float frameDuration;

    // Delta time
    float dT;
};
