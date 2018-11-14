#include "Thread.hpp"

Thread::Thread(Runnable *runnable) {
    pthread_create(&thread, NULL, run, (void*)runnable);
}

void* Thread::run(void * context){
    ((Runnable* )context)->run();
}

int Thread::join() {
    return pthread_join(thread, NULL);
}