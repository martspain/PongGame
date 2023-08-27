#pragma once
#include <string>
#include <entt/entt.hpp>

class Entity; // Forward declaration

class Scene {
  public:
    Scene(const std::string& name);
    ~Scene();

    Entity createEntity(const std::string& name = "No Name");

    entt::registry r;

  private:
    std::string name;
};
