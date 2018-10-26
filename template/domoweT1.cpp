#include<iostream>
#include<vector>
#include<chrono>
#include<list>
#include<algorithm>
#include<stdlib.h>

using namespace std;


class Student
{
private:
    int id;
    int *tab=new int[100];
public:
    int get_id() {return id;};
    void set_id(int value) {id=value;};
    char tt1;
    double tt2;
    float tt3;
Student(unsigned int init_val) {id = init_val;};   // constructor
~Student() {};                                     // destructor


bool operator==(const int &rhs)        //przeciazony operator ==
{
if(this->id==rhs)
    return true;
else
    return false;
}



};


std::vector<int> vectorint;           
std::vector<char> vectorchar;           
std::vector<Student> mojvector;           
std::list<int> listint;
std::list<char> listchar;
std::list<Student> mojlist;

std::vector<int>::iterator iit;
std::vector<char>::iterator cit;
std::vector<Student>::iterator sit;

std::list<int>::iterator liit;
std::list<char>::iterator lcit;
std::list<Student>::iterator lsit;

int main()
{

std::cout <<"Roznice w predkosci PUSH BACK na vektorze i liscie"<<endl;
std::cout<<"VECTOR:"<<endl;

auto start = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
vectorint.push_back(128);

auto end = std::chrono::system_clock::now();          //TIME end
auto elapsed = end - start;



auto start2 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
vectorchar.push_back('c');

auto end2 = std::chrono::system_clock::now();          //TIME end
auto elapsed2 = end2 - start2;


auto start3 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
mojvector.push_back(200);

auto end3 = std::chrono::system_clock::now();          //TIME end
auto elapsed3 = end3 - start3;




//lista

auto start4 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
listint.push_back(128);

auto end4 = std::chrono::system_clock::now();          //TIME end
auto elapsed4 = end4 - start4;



auto start5 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
listchar.push_back('c');

auto end5 = std::chrono::system_clock::now();          //TIME end
auto elapsed5 = end5 - start5;


auto start6 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
mojlist.push_back(200);

auto end6 = std::chrono::system_clock::now();          //TIME end
auto elapsed6 = end6 - start6;



int el=elapsed.count();
int el2=elapsed2.count();
int el3=elapsed3.count(); 
int el4=elapsed4.count();
int el5=elapsed5.count(); 
int el6=elapsed6.count(); 

std::cout <<"vect inty czas: "<< elapsed.count() <<" "<<(el)/(el2/100)<<"%"<<'\n';
std::cout << "vect char czas: "<<elapsed2.count() << " 100%"<<'\n';
std::cout << "vect clas czas: "<<elapsed3.count() << " "<<(el3)/(el2/100)<<"%"<<'\n';

std::cout<<"LISTA:"<<endl;
std::cout <<"list inty czas: "<< elapsed4.count() << " "<<(el4)/(el2/100)<<"%"<<'\n';
std::cout << "list char czas: "<<elapsed5.count() << " "<<(el5)/(el2/100)<<"%"<<'\n';
std::cout << "list clas czas: "<<elapsed6.count() << " "<<(el6)/(el2/100)<<"%"<<'\n';
cout<<endl;


//-----------------------------------------------------------------------------------
std::cout<<"Roznice w predkosci FIND na vektorze i liscie" <<endl;
//vektor find

std::cout<<"VECTOR:"<<endl;
auto start7 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
std::find(vectorint.begin(), vectorint.end(), 30);

auto end7 = std::chrono::system_clock::now();          //TIME end
auto elapsed7 = end7 - start7;
std::cout << "vect inty czas: "<<elapsed7.count() << " "<<'\n';


auto start8 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
std::find(vectorchar.begin(), vectorchar.end(), 'a');

auto end8 = std::chrono::system_clock::now();          //TIME end
auto elapsed8 = end8 - start8;
std::cout << "vect char czas: "<<elapsed8.count() << " "<<'\n';

auto start9 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)

std::find(mojvector.begin(), mojvector.end(), 30);

auto end9 = std::chrono::system_clock::now();          //TIME end
auto elapsed9 = end9 - start9;
std::cout << "vect clas czas: "<<elapsed9.count() << " "<<'\n';



//LISTA FIND:

std::cout<<"LISTA:"<<endl;
auto start10 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
std::find(listint.begin(), listint.end(), 30);

auto end10 = std::chrono::system_clock::now();          //TIME end
auto elapsed10 = end10 - start10;
std::cout << "list inty czas: "<<elapsed10.count() << " "<<'\n';


auto start11 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
std::find(listchar.begin(), listchar.end(), 'a');

auto end11 = std::chrono::system_clock::now();          //TIME end
auto elapsed11 = end11 - start11;
std::cout << "list char czas: "<<elapsed11.count() << " "<<'\n';

auto start12 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)

std::find(mojlist.begin(), mojlist.end(), 30);

auto end12 = std::chrono::system_clock::now();          //TIME end
auto elapsed12 = end12 - start12;
std::cout << "list clas czas: "<<elapsed12.count() << " "<<'\n';






cout<<endl;
std::cout<<"Roznice w predkosci INSERT na vektorze i liscie," <<endl;

//vektor Insert


std::cout<<"VECTOR:"<<endl;
iit=vectorint.begin()+500000;    //rand()%99999;
auto start13 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
vectorint.insert(iit,100);

auto end13 = std::chrono::system_clock::now();          //TIME end
auto elapsed13 = end13 - start13;
std::cout << "vect inty czas: "<<elapsed13.count() << " "<<'\n';


cit=vectorchar.begin()+500000;     //rand()%99999;
auto start14 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
vectorchar.insert(cit,'b');

auto end14 = std::chrono::system_clock::now();          //TIME end
auto elapsed14 = end14 - start14;
std::cout << "vect char czas: "<<elapsed14.count() << " "<<'\n';


sit=mojvector.begin()+500000;       //rand()%99999;
auto start15 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
mojvector.insert(sit,111);

auto end15 = std::chrono::system_clock::now();          //TIME end
auto elapsed15 = end15 - start15;
std::cout << "vect clas czas: "<<elapsed15.count() << " "<<'\n';


std::cout<<"LISTA:                     (szuka lokalizacja 500000-go iteratora)"<<endl;

//LISTA INSERT:

liit=listint.begin();


auto start16 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<500000;i++)
    liit++;
listint.insert(liit,100);

auto end16 = std::chrono::system_clock::now();          //TIME end
auto elapsed16 = end16 - start16;
std::cout << "list inty czas: "<<elapsed16.count() << " "<<'\n';


lcit=listchar.begin();
auto start17 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<500000;i++)
    lcit++;
listchar.insert(lcit,'b');

auto end17 = std::chrono::system_clock::now();          //TIME end
auto elapsed17 = end17 - start17;
std::cout << "list char czas: "<<elapsed17.count() << " "<<'\n';


lsit=mojlist.begin();
auto start18 = std::chrono::system_clock::now();          //TIME start

for (int i=0;i<1000000;i++)
    lsit++;
mojlist.insert(lsit,111);

auto end18 = std::chrono::system_clock::now();          //TIME end
auto elapsed18 = end18 - start18;
std::cout << "list clas czas: "<<elapsed18.count() << " "<<'\n';



//LISTA INSERT wyliczenie bez zmiany iteratora:
cout<<"LISTA:                     (tylko insert bez szukania iteratora)"<<endl;

//liit=listint.begin();


auto start19 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<500000;i++)
    liit++;
listint.insert(liit,100);

auto end19 = std::chrono::system_clock::now();          //TIME end
auto elapsed19 = end19 - start19;
std::cout << "list inty czas: "<<elapsed19.count() << " "<<'\n';


//lcit=listchar.begin();
auto start20 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<500000;i++)
    lcit++;
listchar.insert(lcit,'b');

auto end20 = std::chrono::system_clock::now();          //TIME end
auto elapsed20 = end20 - start20;
std::cout << "list char czas: "<<elapsed20.count() << " "<<'\n';


//lsit=mojlist.begin();
auto start21 = std::chrono::system_clock::now();          //TIME start

//for (int i=0;i<1000000;i++)
    lsit++;
mojlist.insert(lsit,111);

auto end21 = std::chrono::system_clock::now();          //TIME end
auto elapsed21 = end21 - start21;
std::cout << "list clas czas: "<<elapsed21.count() << " "<<'\n';



return 0;
}

