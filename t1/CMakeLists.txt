#voir http://derekmolloy.ie/hello-world-introductions-to-cmake/
#a editer a chaque changement dans la composition du projet. 
#Puis, invoquer a partir du repertoire obj 'cmake ..'  cela creera un MakeFile sous obj/
#todo - OK option de compilation -g -Wall et autres
#     - mettre le objets sous obj et le target (t1) sous release
#     - changer les repertoire inc en include - sous git puis sous CMakeLists.txt
#make doit etre invoque a partir de obj/

cmake_minimum_required(VERSION 3.0.2)
#c++11 standard
set (CMAKE_CXX_STANDARD 11)
project(t1)

find_package(Boost 1.49.0)
include_directories(inc ../common/inc)
add_definitions(-D_REENTRANT)
file(GLOB SOURCES "src/*.cpp" "../common/src/*.cpp")

add_executable(t1 ${SOURCES})
target_link_libraries(t1 curl pthread mysqlclient ${Boost_LIBRARIES})
#target_link_libraries(foo ${Boost_LIBRARIES})
#mode debug
set(CMAKE_BUILD_TYPE Debug)
#compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wno-unused-function")
