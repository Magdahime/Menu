#ifndef KEYBOARD
#define KEYBOARD
#include "Main.hpp"
class TKeyboard{
private:
    std::array<std::string,COMMANDS> commands_list= {
      "add choice", "remove choice",
      "add menu", "remove menu",
      "add submenu", "remove submenu",
      "assign function", "help",
      "expand submenu", "fold submenu",
      "choose",
      "add file", "open file",
    };
public:
    int check(std::string command);
    void show_me_the_list();
    void choose();
    void get_command();
};
#endif
