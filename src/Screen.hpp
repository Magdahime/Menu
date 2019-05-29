#ifndef SCREEN
#define SCREEN
#include "Main.hpp"
#include "Basic_window.hpp"
#include "Menu.hpp"
#include "Keyboard.hpp"
class TScreen: virtual public Basic_window{
private:
    Tmenu* actual_menu;
    TKeyboard * Keyboard;
public:
    TScreen();
    void draw_yourself();
};
#endif
