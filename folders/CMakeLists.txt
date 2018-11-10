cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

project(przyklad)

add_executable(
   przyklad 
   main.cpp
   apl/timemaster.hpp
   apl/timemaster.cpp
   driver/ethernet.hpp
   driver/ethernet.cpp
   rte/communicationmanager.hpp
   rte/communicationmanager.cpp
   service/router.hpp
   service/router.cpp
   publ/errorcode.hpp
   publ/itimemaster.cpp
   publ/itimemaster.hpp

)
