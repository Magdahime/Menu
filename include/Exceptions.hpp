#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include "Main.hpp"
class TExceptions{
private:
    static int how_many_times;
    static void increase_number();
public:
    static int bad_int_data();
    static int how_many();
    
};
#endif
