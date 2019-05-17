#ifndef FUNCTIONS
#define FUNCTIONS
#include "Main.hpp"
class Tfunction{
private:
    int my_number;
    std::string name;
    static int how_many;
    static void increase_number();
public:
    Tfunction();
    std::string tell_me_name();
    void do_something();
    int give_me_number();
};
#endif
