#ifndef WINDOW_HPP
#define WINDOW_HPP
class Tmenu;
#include "Menu.hpp"
#include "Main.hpp"
#include "Functions.hpp"
#include "Basic_window.hpp"
class TWindow : public Basic_window{
private:
    Tmenu* submenu;
    Tfunction* function;
public:
    TWindow():submenu(nullptr),function(nullptr){}
    TWindow(Tmenu* menu_pointer):submenu(menu_pointer),function(nullptr){}
    TWindow(Tfunction * func_pointer):submenu(nullptr),function(func_pointer){}
    void draw_yourself();
    void do_something();
    void operator=(Tfunction function1);
    void operator=(Tmenu submenu1);
    bool is_empty();
};

#endif

