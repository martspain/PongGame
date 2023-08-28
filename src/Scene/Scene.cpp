#include <print.h>
#include "Scene.h"
#include "ECS/Entity.h"
#include "ECS/SystemTypes/SetupSystem.h"

Scene::Scene(const std::string& name)
  : name(name) {
    print("Scene Created: ", name);
}

Scene::~Scene() {
  print("Scene Deleted");

  for (auto s: setupSystems) {
    delete s;
  }
}

Entity Scene::createEntity(const std::string& name) {
  Entity entity = { r.create(), this };
  return entity;
}

void Scene::addSetupSystem(SetupSystem* system) {
  setupSystems.push_back(system);
}

void Scene::setup() {
  for(const auto& s: setupSystems) {
    s->run();
  }
}