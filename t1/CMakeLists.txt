#a editer a chaque changement dans la composition du projet. Puis, invoquer a partir du repertoire obj cmake ... Le binaire sera sous obj/
cmake_minimum_required(VERSION 3.0.2)
project(t1)

include_directories(inc ../common/inc)

file(GLOB SOURCES "src/*.cpp" "../common/src/*.cpp")

add_executable(t1 ${SOURCES})
