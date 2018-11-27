cmake_minimum_required (VERSION 2.6)
project (pr)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++98 -Lpthread -Wall -Werror -pedantic")

find_package (Threads)
add_executable (pr 
    main.cpp
    eEcuNum.h
    eErrorCodes.h
    eStates.h
    ILogger.h
    IObserver.h
    ISheduler.h
    Loger.cpp
    Loger.hpp
    sheduler.cpp
    sheduler.hpp
    Ticks.hpp
    swc/HUSwC.cpp
    swc/HUSwC.hpp
    swc/IPCSwC.cpp
    swc/IPCSwC.hpp
    swc/ISwC.h
    swc/ISwC.cpp
    swc/SensorMasterImpl.cpp
    swc/SensorMasterImpl.h
    swc/timemaster.cpp
    swc/timemaster.h
    rte/CommunicationMgrImplementation.cpp
    rte/CommunicationMgrImplementation.h
 
 
    )
target_link_libraries (pr ${CMAKE_THREAD_LIBS_INIT})
