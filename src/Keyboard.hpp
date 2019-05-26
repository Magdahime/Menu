#ifndef KEYBOARD
#define KEYBOARD
#include "Main.hpp"
#include "Menu.hpp"
class TKeyboard{
private:
    Tmenu * My_menu;
    std::array<std::string,COMMANDS> commands_list= {
      "help",
      "add choice", "remove choice",
      "add menu", "remove menu",
      "add submenu", "remove submenu",
      "assign function",
      "expand submenu", "fold submenu",
      "choose",
      "add file", "open file","save to file",
      "exit", "back",
    };
public:
    int check(std::string command);
    int get_int();
    void show_me_the_list();
    void choose(int choice);
    void get_command();
    void change_keyboard(Tmenu* new_menu);
    void clrscrs();
};
#endif
