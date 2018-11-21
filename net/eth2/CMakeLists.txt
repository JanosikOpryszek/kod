cmake_minimum_required (VERSION 2.6)
project (pr)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++98 -Lpthread")

find_package (Threads)
add_executable (pr 
    main.cpp
    Ethernetdriverserver.cpp
    Ethernetdriverserver.cpp
    eErrorCodes.h
    IDriver.h
    Iethernet.hpp
    IEthernetdriverserver.hpp
    MSGveryficator.cpp
    MSGveryficator.hpp
    imsgvermethod.h
    )
target_link_libraries (pr ${CMAKE_THREAD_LIBS_INIT})
