#include <iostream>
#include <time.h>
#include <chrono>
#include<stdint.h>

class Ticks
{
    public:
    Ticks(uint32_t a_ratio)        //ratio for PI = 1000
    {
        m_u32Time=0;
        m_u32Ratio=a_ratio;
    }

    void ticks(uint32_t a_milisec)
    {
        m_u32Time=0;
        m_u32Times=static_cast<uint32_t>(clock());  //START TICK
        while(m_u32Time<(a_milisec*m_u32Ratio))
        {

            m_u32Timed=static_cast<uint32_t>(clock());
            m_u32Time=m_u32Timed-m_u32Times;
        }
    }

    private:
    uint32_t m_u32Time;
    uint32_t m_u32Times;
    uint32_t m_u32Timed;
    uint32_t m_u32Ratio;

};



using namespace std;
int main(void)
{
Ticks ticker(1000);

// Record start time
auto start = std::chrono::high_resolution_clock::now();

ticker.ticks(100);

// Record end time
auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed=finish-start;

cout << "*************************"<<endl;
cout << "*************************"<<endl;

cout << "times from start to end " << elapsed.count() <<endl;
return 0;
}
