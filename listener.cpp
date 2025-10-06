
#include <iostream>

class Listener
{
public:
    virtual ~Listener() {};
    
    virtual void init() = 0;
    virtual void iter_loop(int iter) = 0;
    virtual void done() = 0;

};

class ListenerEx: public Listener
{
public:
    ~ListenerEx()
    {
        std::cout << "~"<< std::endl;
    }
    
    void init()
    {
        std::cout << "init "<< std::endl;
    }
    
    void iter_loop(int iter)
    {
        std::cout << "iter " << iter << std::endl;
    }
    
    void done()
    {
        std::cout << "done "<< std::endl;
    }

};

class MainLoop
{
public:
    MainLoop()
    {
        std::cout << "MainLoop"<< std::endl;

    }
    ~MainLoop()
    {
        std::cout << "~MainLoop"<< std::endl;

    }
    
    void set_listener(Listener* listener)
    {
        _listener = listener;    
    }
    
    
    void exec()
    {
        _listener->init();
        
        int iter = 0;
        
        while(iter <= 10) 
        {
            _listener->iter_loop(iter);
            
            iter++;        
        }
        
        _listener->done();
        
    }
    
    Listener* _listener;

};

int main()
{
    MainLoop main_loop;
    
    main_loop.set_listener(new ListenerEx());
    
    main_loop.exec();
    

    return 0;
}

