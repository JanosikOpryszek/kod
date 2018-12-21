cmake_minimum_required (VERSION 2.6)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

project (pr)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++98 -Lpthread -Wall -Werror -pedantic")

find_package (Threads)
add_executable (pr 

    ILogger.h
    #    Loger.hpp
    main.cpp
    Ethernetdriverserver.cpp
    Ethernetdriverserver.hpp
    eErrorCodes.h
    IDriver.h
    Iethernet.hpp
    IEthernetdriverserver.hpp
    MSGveryficator.cpp
    MSGveryficator.hpp
    imsgvermethod.h
    eEcuNum.h
    eStates.h
    )
target_link_libraries (pr ${CMAKE_THREAD_LIBS_INIT})
