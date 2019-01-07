#include<iostream>

struct Car { 
        Car() {
            std::cout<<"konstruktor Car"<<std::endl;
        }
        ~Car()
        {
            std::cout<<"destruktor Car"<<std::endl;


        }
};

struct Sport : public Car {
Sport()  {
 std::cout<<"konstruktor Sport"<<std::endl;

 throw 1;
}



~Sport() {
std::cout<<"destruktor Sport"<<std::endl;
}


int a;
int b;



};



int main ()
{

Sport aa;



return 0;
}
