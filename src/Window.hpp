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
    TFunction* function;
public:
    TWindow():submenu(nullptr),function(nullptr){}
    TWindow(Tmenu* menu_pointer):submenu(menu_pointer),function(nullptr){}
    TWindow(TFunction * func_pointer):submenu(nullptr),function(func_pointer){}
    Tmenu* give_me_submenu_pointer();
    std::string tell_me_name();
    void remove_data();
    void draw_yourself();
    void do_something();
    void operator=(TFunction* function1);
    void operator=(Tmenu** submenu1);
    bool is_empty();
    bool is_submenu();
};

#endif

