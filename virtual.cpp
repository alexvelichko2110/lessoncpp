
#include <iostream>

class Base 
{
public:
    Base()
    {
        std::cout << "Base"<< std::endl;
    }
    virtual ~Base()
    {
        std::cout << "~Base"<< std::endl;
    }
    
    virtual void show()
    {
        std::cout << "Base :: show "<< std::endl;
    }
};

class Derive : public Base
{
public:
    Derive()
    {
        std::cout << "Derive"<< std::endl;

    }
    ~Derive()
    {
        std::cout << "~Derive"<< std::endl;

    }
    
    virtual void show()
    {
        std::cout << "Derive :: show "<< std::endl;
    }

};

int main()
{
    Derive *d = new Derive();
    
    Base *b = d;
    
    b->show();


    return 0;
}

