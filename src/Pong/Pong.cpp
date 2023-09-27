#include <iostream>

#include "Pong.h"
#include "Systems.h"

#include "ECS/Entity.h"

Pong::Pong(const char* name, int width, int height)
: Game(name, width, height) {
  Scene* gameplayScene = createGameplayScene();
  setScene(gameplayScene);
}

Pong::~Pong() {
}

Scene* Pong::createGameplayScene() {
  Scene* scene = new Scene("GAMEPLAY SCENE");

  Entity ball = scene->createEntity("BALL", 10, 10);
  ball.addComponent<SizeComponent>(20, 20);
  ball.addComponent<SpeedComponent>(200, 200);
  ball.addComponent<ColliderComponent>(false, 0);

  // Player One (Left)
  Entity paddleLeft = scene->createEntity("PLAYER 1", 0, (screen_height/2));
  paddleLeft.addComponent<SizeComponent>(20, 100);
  paddleLeft.addComponent<SpeedComponent>(0, 0);
  paddleLeft.addComponent<PlayerLeftComponent>(400);
  
  // Player Two (Right)
  Entity paddleRight = scene->createEntity("PLAYER 2", (screen_width-20), (screen_height/2));
  paddleRight.addComponent<SizeComponent>(20, 100);
  paddleRight.addComponent<SpeedComponent>(0, 0);
  paddleRight.addComponent<PlayerRightComponent>(400);


  // scene->addSetupSystem(new HelloWorldSystem());
  scene->addRenderSystem(new RectRenderSystem());
  scene->addUpdateSystem(new BounceUpdateSystem());
  scene->addUpdateSystem(new MovementUpdateSystem(screen_width, screen_height));
  scene->addEventSystem(new PlayerLeftInputSystem());
  scene->addEventSystem(new PlayerRightInputSystem());

  scene->addUpdateSystem(new CollisionDetectionUpdateSystem());

  return scene;
}