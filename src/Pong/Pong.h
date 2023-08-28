#pragma once
#include "Game/Game.h"
#include "Scene/Scene.h"

class Pong: public Game {
  public:
    Pong(const char* name, int width, int height);
    ~Pong();

    void update() override;
    void render() override;
    void handleEvents() override;
    bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);

    Scene* createGameplayScene();

  private:
    int bg_R, bg_G, bg_B;
    int ballSpeedX, ballSpeedY, playerSpeed;
    char* winMessage;
    SDL_Rect ball;
    SDL_Rect paddleOne;
    SDL_Rect paddleTwo;
};
