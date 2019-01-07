#include<iostream>
#include<map>

using namespace std;


struct Dictionary
{
    
    std::map<int,string> MyMap;
    
    void insert(const std::string& word)
    {
    int temphash=Hash(word);
    MyMap.emplace(temphash,word);

    }


    bool find(const std::string& word) const
    {
    
    int temphash=Hash(word);

    if( MyMap.find(temphash)!=MyMap.end() )
        return true;
    else
        return false;
      
    }

    bool empty() const;
    


    int Hash(const std::string& key) const
    {
    int _value = std::hash<std::string>{}(key);
                
        return _value;
    }


};



/*
template<typename Data>
using MyMap = std::map<Hash, Data, ??>;
*/


/*
template<typename Data>
struct HashMap {
      
      Data& at(string key);
        void put(string key, Data);
          bool check(string) const noexcept;

            MyMap _map;
};
*/



int main ()
{

Dictionary mojslownik;

mojslownik.insert("dupa");


for(auto element : mojslownik.MyMap )
    cout<< element.second;

cout<<endl;


cout<<mojslownik.find("dupa")<<endl;

    



return 0;
}




