#include<iostream>
#include<string>
#include<string.h>



using namespace std;

char m_cBufferSS[1024];
string a_strTab="1203456";


int main()
{
cout<<a_strTab<<endl;
//a_strTab.append(  );
//a_strTab.append("789");

cout<<a_strTab<<endl;

//strcpy(m_cBufferSS,a_strTab.c_str() );
memcpy(m_cBufferSS, a_strTab.data(),8 );
//copy(a_strTab.begin(), a_strTab.end(), m_cBufferSS);

a_strTab.copy(m_cBufferSS, 8);


for(int i=0;i<8;i++)
    cout<<m_cBufferSS[i]<<endl;






return 0;
}
