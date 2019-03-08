#include<iostream>
#include<string>



using namespace std;


class Moja
{
public:
Moja();
Moja(string a);
~Moja();

void printt();


private:
string mojs;

};

class MM
{
public:

MM();

~MM();

void pp();

private:
Moja moja =Moja();
int aa;

};


