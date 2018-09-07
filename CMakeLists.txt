cmake_minimum_required(VERSION 3.10)
project(Regin_mountain_of_treasures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp Vector.cpp Vector.h Point.cpp Point.h Body.cpp Body.h BodyType.cpp BodyType.h Entity.cpp Entity.h)
add_executable(Regin_mountain_of_treasures ${SOURCE_FILES})

target_link_libraries(Regin_mountain_of_treasures SDLmain SDL)

file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})