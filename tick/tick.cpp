#include <iostream>
#include <time.h>
#include <chrono> 

using namespace std;
int main(void)
{
    int times,timed;

// Record start time
auto start = std::chrono::high_resolution_clock::now();    
    times=clock();  //START TICK


    double a=3;
for (int i=0;i<30000000;i++)
    a*=3;


    timed=clock();  //STOP TICK
    // Record end time
auto finish = std::chrono::high_resolution_clock::now();
    times=timed-times;

std::chrono::duration<double> elapsed=finish-start;
 //   auto elapsed=finish-start;
//int tt=elapsed.count();

    cout << "ticks from start to end " << times <<endl;
    cout << "times from start to end " << elapsed.count() <<endl;
}
