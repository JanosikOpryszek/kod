cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
project(przyklad)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package (Threads)


add_executable(
   przyklad 
   global.cpp
   main.cpp 
   apl/timemaster.hpp
   apl/timemaster.cpp
   driver/ethernet.hpp
   driver/ethernet.cpp
   rte/communicationmanager.hpp
   rte/communicationmanager.cpp
   service/router.hpp
   service/router.cpp
   service/lcm.hpp 
   service/lcm.cpp 
   service/starter.hpp
   service/starter.cpp
   publ/errorcode.hpp
   publ/interface.hpp
)
target_link_libraries (przyklad ${CMAKE_THREAD_LIBS_INIT})
