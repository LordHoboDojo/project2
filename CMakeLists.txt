cmake_minimum_required(VERSION 3.17)
project(project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(project2 main.cpp Seat.cpp Seat.h Node.cpp Node.h Auditorium.cpp Auditorium.h)