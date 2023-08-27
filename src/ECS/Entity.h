#pragma once
#include "Scene/Scene.h"

class Entity {
  public:
    Entity(entt::entity e, Scene* s) {
      print("Entity created.");
      handle = e;
      scene = s;
    }
    ~Entity() {
      print("Entity deleted");
    }

    template<typename T, typename ...Args>
    T& addComponent(Args&&... args) {
      return scene->r.emplace<T>(handle, std::forward<Args>(args)...);
    }

    template<typename T>
    void removeComponent(){
      scene->r.remove<T>(handle);
    }

  private:
    entt::entity handle;
    Scene* scene;
};
