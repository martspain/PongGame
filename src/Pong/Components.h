#include "ECS/Components.h"

struct SizeComponent {
  int w;
  int h;
};

struct PlayerLeftComponent {
  int moveSpeed;
};

struct PlayerRightComponent {
  int moveSpeed;
};

struct ColliderComponent {
  bool triggered;
  int transferSpeed;
};