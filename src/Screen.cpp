#include "Main.hpp"
#include "Screen.hpp"
#include <memory>
TScreen::TScreen()
{
    actual_menu = new (Tmenu);
    Keyboard = new(TKeyboard);
    File_handler=new(TFile_handler);
    actual_menu->give_me_my_keyboard(Keyboard);
    Keyboard->change_keyboard(actual_menu);
    Keyboard->get_command();
}

void TScreen::draw_yourself()
{
    actual_menu->draw_yourself();
}
void TScreen::extract_data()
{
    std::cout<<"You are currently saving your data to file."<<std::endl;
    actual_menu->create_window_with_submenu(*File_handler->get_data_from_file());   
}
void TScreen::save_data()
{
    std::vector<TWindow>* pointer_vector=actual_menu->send_data();
    std::cout<<"You are currently saving your data to file."<<std::endl;
    File_handler->save_data_to_file(*pointer_vector);
}
