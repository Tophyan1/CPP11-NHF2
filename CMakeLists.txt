cmake_minimum_required(VERSION 3.15)
project(Charge)

set(CMAKE_CXX_STANDARD 17)

add_executable(Charge main.cpp Particle.h Point.h MovingParticle.h Area.h Level.h)