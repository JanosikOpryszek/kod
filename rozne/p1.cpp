#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

//       przyklad pauli na uruchomienie metody obiektu pthreadem (POSIX)
//       zamiast (void*(*)(void*)) mozna dac:   typedef void * (*THREADFUNCPTR)(void *);


class Task{
public:
	int number;
	static int staticNumber;
	void * execute();


	Task(int num){
	this->number=num;
	staticNumber++;
	}

	void * write();
};

int Task::staticNumber = 0;

void * Task::execute(){
	cout << "Task :: execute from Thread ID : " << pthread_self() << 
	" Static: " << staticNumber << " Non-static: " << this->number << endl;
	return NULL;
}

void * Task::write(){
	cout << "Task :: write from Thread ID : " << pthread_self() << 
	" Static: " << staticNumber << " Non-static: " << this->number << endl;
	return NULL;
}
int main()
{
	pthread_t threadId1;
	pthread_t threadId2;

	for(int i=10; i>0;--i){
		Task * taskPtr = new Task(i);
		pthread_create(&threadId1, NULL,(void*(*)(void*))&Task::execute,taskPtr);
		pthread_create(&threadId2, NULL,(void*(*)(void*))&Task::write,taskPtr);
		sleep(1);
		delete taskPtr;
	}
	
	cout << "Exiting Main" << endl;

	return 0;
}
