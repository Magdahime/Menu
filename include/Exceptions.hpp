#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include "Main.hpp"
#include <limits>
class TExceptions{
private:
    static int how_many_times;
    static void increase_number();
public:
    static int bad_int_data(int limit =std::numeric_limits<int>::max());
    static int how_many();
    static std::string bad_string();
    static bool checking_string(char* suspicious_string);
    
};
#endif
