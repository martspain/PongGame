#pragma once
#include "Game.h"

class Pong: public Game {
  public:
    Pong(const char* name, int width, int height);
    ~Pong();

    void setup() override;
    void update() override;
    void render() override;
    void handleEvents() override;
    bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);

  private:
    int bg_R, bg_G, bg_B;
    int ballSpeedX, ballSpeedY, playerSpeed;
    char* winMessage;
    SDL_Rect ball;
    SDL_Rect paddleOne;
    SDL_Rect paddleTwo;
};
