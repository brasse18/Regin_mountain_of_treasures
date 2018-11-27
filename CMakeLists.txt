cmake_minimum_required(VERSION 3.10)
project(Regin-mountain-of-treasures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

#include_directories(${PROJECT_SOURCE_DIR}/include)
#link_directories(${PROJECT_SOURCE_DIR}/lib)

#Vector.cpp Vector.h Point.cpp Point.h Body.cpp Body.h BodyType.cpp BodyType.h Entity.cpp Entity.h

set(SOURCE_FILES main.cpp Game.cpp Game.h Object.cpp Object.h)
add_executable(Regin-mountain-of-treasures ${SOURCE_FILES})

target_link_libraries(Regin-mountain-of-treasures SDL2 SDL2_image SDL2_ttf)


file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})