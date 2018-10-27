#include<iostream>
#include<map>

using namespace std;


struct HASH {

int aa;
};


struct Dictionary
{
    
    //SH nowytyp;

    auto compare = [](HASH a1, HASH a2)-> bool 
    {
    return a1.aa>a2.aa ? true:false;
    };


    std::map<HASH,string, decltype(compare)> MyMap{compare};


    
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




