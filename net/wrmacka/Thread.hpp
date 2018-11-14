#pragma once

#include <pthread.h>
#include "Runnable.hpp"

class Thread {
    pthread_t thread;

    static void* run(void * context);
public:
    Thread(Runnable *runnable);
    int join();
};