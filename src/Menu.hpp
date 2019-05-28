#ifndef MENU_HPP
#define MENU_HPP
#include "Main.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Basic_window.hpp"
#include <deque>
class TWindow;
class TKeyboard;
class Tmenu : public Basic_window{
private:
     std::string name;
     std::string get_name();
     Tmenu* My_ancestor;
     Tmenu* My_successor;
     static TKeyboard* My_keyboard;
     std::vector<TWindow> Mywindows;
     std::deque<TFunction> Functions;
     /////////////////////////////////////////////////////
     int choose_function();
     int choose_slot();
     int get_int(unsigned int limit);
public:
    std::string tell_me_name();
    std::vector<TWindow>* send_data();
    void make_choice();
    void remove_data();
    void print_array();
    int create_new_function();
    void draw_yourself();
    void add_empty_slot();
    void remove_slot();
    void fold_submenu();
    void expand_submenu();
    void assign_function_to_empty_slot();
    void assign_menu_to_empty_slot();
    bool get_ans();
    void give_me_my_keyboard(TKeyboard* new_keyboard);
    void create_window_with_function();
    void create_window_with_submenu(std::string name);
    void create_window_with_submenu(Tmenu* pointer_to_submenu);
    Tmenu* search_for_window(std::string title);
};

#endif
