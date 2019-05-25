#ifndef MENU_HPP
#define MENU_HPP
#include "Main.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Basic_window.hpp"
#include <deque>
class TWindow;
class Tmenu : public Basic_window{
private:
     std::string name;
     std::vector<TWindow> Mywindows;
     std::deque<Tfunction> Functions;
     /////////////////////////////////////////////////////
     int choose_function();
     int choose_slot();
     int get_int();
public:
    void print_array();
    int create_new_function();
    void draw_yourself();
    std::string tell_me_name();
    void add_empty_slot();
    void remove_empty_slot();
    void remove_submenu();
    void fold_submenu();
    void expand_submenu();
    void assign_function_to_empty_slot();
    void assign_menu_to_empty_slot();
    bool get_ans();
};

#endif
