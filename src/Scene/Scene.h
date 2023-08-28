#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <entt/entt.hpp>

#include "ECS/SystemTypes/SetupSystem.h"

class Entity; // Forward declaration
// class SetupSystem;
// class EventSystem;
// class UpdateSystem;
// class RenderSystem;

class Scene {
  public:
    Scene(const std::string& name);
    ~Scene();

    Entity createEntity(const std::string& name = "No Name");

    // template<typename T>
    // void addSetupSystem(auto&&... args) {
    //   // const auto& system = std::make_unique<T>(std::forward<decltype(args)>(args)...);
    //   // system->setScene(this);
    //   // return setupSystems.emplace_back(system);
    //   setupSystems.emplace_back(std::forward<decltype(args)>(args)...);
    //   setupSystems.back()->setScene(this);
    //   return setupSystems.back();
    // }

    void addSetupSystem(SetupSystem* system);

    void setup();

    entt::registry r;

  private:
    std::string name;

    std::vector<SetupSystem*> setupSystems;
};
