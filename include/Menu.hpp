#ifndef MENU_HPP
#define MENU_HPP
#include "Main.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Basic_window.hpp"
class TWindow;
class Tmenu : public Basic_window{
private:
     std::vector<TWindow> Mywindows;
     std::array<Tfunction,COMMANDS> Functions;
     std::string name;
public:
    void draw_yourself();
    void do_something();
    std::string tell_me_name();
    void add_empty_slot();
    void remove_empty_slot();
    void add_submenu();
    void remove_submenu();
    void fold_submenu();
    void expand_submenu();
    void assign_function_to_empty_slot();
    void assign_menu_to_empty_slot();
};

#endif
