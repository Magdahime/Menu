#ifndef BASIC_WINDOW
#define BASIC_WINDOW
#include "Main.hpp"
class Basic_window{
protected:
    std::string name;
public:
    virtual void draw_yourself()=0;
};
#endif
