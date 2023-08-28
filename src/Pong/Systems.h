#pragma once

#include <print.h>
#include "ECS/System.h"

class HelloWorldSystem : public SetupSystem {
  public:
    HelloWorldSystem(){
      print("Hello World Constructor");
    }
    ~HelloWorldSystem(){
      print("Hello World Destructor");
    }
    void run() {
      print("Hello Worldddd :)");
    }
};