#ifndef FUNCTIONS
#define FUNCTIONS
#include "Main.hpp"
class Tfunction{
private:
    static int how_many;
    std::string name;
    void increase_number();
public:
    Tfunction();
    std::string tell_me_name();
    void do_something();
};
#endif
