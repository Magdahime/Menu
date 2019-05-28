#ifndef SCREEN
#define SCREEN
#include "Main.hpp"
#include "Basic_window.hpp"
#include "Menu.hpp"
#include "Keyboard.hpp"
#include "File_handler.hpp"
class TScreen: public Basic_window{
private:
    Tmenu* actual_menu;
    TKeyboard * Keyboard;
    TFile_handler * File_handler;
public:
    TScreen();
    void draw_yourself();
    void extract_data();
    void save_data();
};
#endif
