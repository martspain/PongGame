#include <iostream>

#include "Pong.h"
#include "Systems.h"

#include "ECS/Entity.h"
// #include "ECS/Components.h"

// Scene* currentScene;

Pong::Pong(const char* name, int width, int height)
: Game(name, width, height) {
  // bg_R = 0, bg_G = 0, bg_B = 0;
  // winMessage = "Game Over. No one won. :(";

  // Scene* scene = new Scene("Pong Scene");
  // scene->createEntity("Paddle 1");
  currentScene = createGameplayScene();
}

Pong::~Pong() {
  print("Pong Destructor");

  print("######################");
  print("######################");
  print("######################");
  print("======================");
  print(winMessage);
  print("======================");
  print("######################");
  print("######################");
  print("######################");

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Pong::checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
  // Calculate the sides of rectA
  int leftA = rectA.x;
  int rightA = rectA.x + rectA.w;
  int topA = rectA.y;
  int bottomA = rectA.y + rectA.h;

  // Calculate the sides of rectB
  int leftB = rectB.x;
  int rightB = rectB.x + rectB.w;
  int topB = rectB.y;
  int bottomB = rectB.y + rectB.h;

  // Check for collision
  if (rightA <= leftB || leftA >= rightB || bottomA <= topB || topA >= bottomB) {
    // No collision
    return false;
  } else {
    // Collision detected
    return true;
  }
}

Scene* Pong::createGameplayScene() {
  Scene* scene = new Scene("Gameplay Scene");

  scene->addSetupSystem(new HelloWorldSystem());

  return scene;
}

// void Pong::setup() {
//   print("pong setup");

//   ball.x = 20;
//   ball.y = 20;
//   ball.w = 20;
//   ball.h = 20;
  
//   // Player One (left)
//   paddleOne.x = 0;
//   paddleOne.y = (screen_height / 2) - 50;
//   paddleOne.w = 20;
//   paddleOne.h = 100;
  
//   // Player Two (right)
//   paddleTwo.x = screen_width - 20;
//   paddleTwo.y = (screen_height / 2) - 50;
//   paddleTwo.w = 20;
//   paddleTwo.h = 100;

//   // Ball speed
//   ballSpeedX = 1;
//   ballSpeedY = 1;

//   // Player Speed
//   playerSpeed = 15;

//   currentScene->setup();
// }

void Pong::update() {
  print("pong update");

  // P2 Wins
  if (ball.x <= 0) {
    isRunning = false;
    winMessage = "P2 (Left) wins!! :D";
  }
  // P1 Wins
  else if (ball.x+20 >= screen_width) {
    isRunning = false;
    winMessage = "P1 (Right) wins!! :D";
  }

  else {
    // Bounces (only vertical axis)
    if (ball.y <= 0 || ball.y >= screen_height-ball.h) {
      ballSpeedY *= -1;

      // Increase ball's speed
      if (ballSpeedX < 0) {
        ballSpeedX -= 1;
      } else {
        ballSpeedX += 1;
      }

      if (ballSpeedY < 0) {
        ballSpeedY -= 1;
      } else {
        ballSpeedY += 1;
      }
    }

    // Collision between ball and player
    if (checkCollision(paddleOne, ball) || checkCollision(paddleTwo, ball)) {
      ballSpeedX *= -1;
      
      // Increase ball's speed
      if (ballSpeedX < 0) {
        ballSpeedX -= 1;
      } else {
        ballSpeedX += 1;
      }

      if (ballSpeedY < 0) {
        ballSpeedY -= 1;
      } else {
        ballSpeedY += 1;
      }

    }

    ball.x += ballSpeedX;
    ball.y += ballSpeedY;
  }


}

void Pong::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    if (event.type == SDL_QUIT) {
      isRunning = false;
    }
  }

  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

  // Check for multiple key inputs
  if (currentKeyStates[SDL_SCANCODE_W]) {
    // Handle 'W' key press
    if (paddleOne.y > 0) {
      paddleOne.y -= playerSpeed;
    }
  }

  if (currentKeyStates[SDL_SCANCODE_S]) {
    // Handle 'S' key press
    if (paddleOne.y + paddleOne.h < screen_height) {
      paddleOne.y += playerSpeed;
    }
  }

  if (currentKeyStates[SDL_SCANCODE_UP]) {
    // Handle 'UP' key press
    if (paddleTwo.y > 0) {
      paddleTwo.y -= playerSpeed;
    }
  }

  if (currentKeyStates[SDL_SCANCODE_DOWN]) {
    // Handle 'DOWN' key press
    if (paddleTwo.y + paddleTwo.h < screen_height) {
      paddleTwo.y += playerSpeed;
    }
  }
}

void Pong::render() {
  print("pong render");

  SDL_SetRenderDrawColor(renderer, bg_R, bg_G, bg_B, 255);
  SDL_RenderClear(renderer);

  // Draw game
  // Ball
  SDL_SetRenderDrawColor(renderer, 255-bg_R, 255-bg_G, 255-bg_B, 255);
  SDL_RenderFillRect(renderer, &ball);

  // Player One (Bottom)
  SDL_RenderFillRect(renderer, &paddleOne);
  
  // Player Two (Top)
  SDL_RenderFillRect(renderer, &paddleTwo);

  SDL_RenderPresent(renderer);
}