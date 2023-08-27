#include "Scene.h"
#include <print.h>
#include "ECS/Entity.h"

Scene::Scene(const std::string& name)
  : name(name) {
    print("Scene Created");
}

Scene::~Scene() {
    print("Scene Deleted");
}

Entity Scene::createEntity(const std::string& name) {
  Entity entity = { r.create(), this };
  return entity;
}