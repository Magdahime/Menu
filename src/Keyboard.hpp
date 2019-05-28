#ifndef KEYBOARD
#define KEYBOARD
#include "Main.hpp"
#include "Menu.hpp"
#include "File_handler.hpp"
class TKeyboard{
private:
    Tmenu * My_menu;
    TFile_handler File_handler;
    
    std::array<std::string,COMMANDS> commands_list= {
      "help",
      "add choice", "remove choice",
      "add submenu", "remove submenu",
      "function",
      "go", "back",
      "choose","open file","save to file",
      "exit",
    };
public:
    int check(std::string command);
    int get_int();
    void show_me_the_list();
    void choose(int choice);
    void get_command();
    void change_keyboard(Tmenu* new_menu);
    void extract_data();
    void save_data();
    void clrscrs();
};
#endif
