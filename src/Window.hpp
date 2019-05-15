#ifndef WINDOW_HPP
#define WINDOW_HPP
class Tmenu;
#include "Menu.hpp"
#include "Main.hpp"
#include "Functions.hpp"
class TWindow{
private:
    std::array<std::array<char,80>,5> window;
    Tmenu* submenu;
    Tfunction* function;
public:
    TWindow():submenu(nullptr),function(nullptr){}
    TWindow(Tmenu* menu_pointer):submenu(menu_pointer),function(nullptr){}
    TWindow(Tfunction * func_pointer):submenu(nullptr),function(func_pointer){}
    void draw_yourself();
    void center();
};

#endif

