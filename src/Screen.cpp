#include "Main.hpp"
#include "Screen.hpp"
TScreen::TScreen()
{
    actual_menu = new (Tmenu);
    Keyboard = new(TKeyboard);
    actual_menu->give_me_my_keyboard(Keyboard);
    Keyboard->change_keyboard(actual_menu);
    Keyboard->get_command();
}

void TScreen::draw_yourself()
{
    actual_menu->draw_yourself();
}
