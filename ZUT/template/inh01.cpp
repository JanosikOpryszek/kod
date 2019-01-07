#include<iostream>


struct Human {
    std::string name() const noexcept;
    protected:
    virtual void sex() const noexcept
    {

    } 
};

struct Man :public  Human {
    public:

void sex() const noexcept override
{

}
};


struct ManA : public Human {};


int main()
{
ManA aabb;
Man bbcc;
bbcc.sex();
//aabb.sex();

return 0;
}
