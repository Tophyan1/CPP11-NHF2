cmake_minimum_required(VERSION 3.15)
project(Charge)

set(CMAKE_CXX_STANDARD 17)

add_executable(Charge main.cpp Point.h Vector.h PointCharge.h Particle.h MovableParticle.h Collidable.h Rectangle.h Wall.h Goal.h Level.cpp Level.h Game.cpp Game.h)