cmake_minimum_required(VERSION 3.26)

project(MARTSPAIN_GEA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# SDL2 Lib
# Reference: https://wiki.libsdl.org/SDL2/FAQWindows#my_application_shows_no_terminal_with_debug_messages_1
set(SDL2_NO_MWINDOWS)
find_package(SDL2 REQUIRED)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  ${SOURCES}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
  ${PROJECT_NAME}
  ${SDL2_LIBRARIES}
)