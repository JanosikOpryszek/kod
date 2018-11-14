cmake_minimum_required (VERSION 2.6)
project (eth)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++98 -pthread")

find_package (Threads)
add_executable (eth 
    main.cpp
    ethernetdriverclient.cpp
    ethernetdriverclient.hpp
    ethernetdriverserver.cpp
    ethernetdriverserver.cpp
    interface.hpp
    )
target_link_libraries (eth ${CMAKE_THREAD_LIBS_INIT})
