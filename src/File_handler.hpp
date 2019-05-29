#ifndef FILE_HANDLER
#define FILE_HANDLER
#include "Main.hpp"
#include "Exceptions.hpp"
#include "Window.hpp"
#include "Menu.hpp"
#include "Functions.hpp"
#include <fstream>
const std::string menu_key={"MENU:"};
const size_t menu_key_size={menu_key.size()};
const std::string function_key={"FUNCTION"};
const size_t function_key_size={function_key.size()+1};
const std::string new_window_key={"NEW WINDOW"};
const size_t new_window_key_size={new_window_key.size()+1};
const std::string title_window_key={"TITLE:"};
const size_t title_window_key_size={title_window_key.size()};
const std::string exit_key={"EXIT"};
class TFile_handler{
private:
    std::ifstream handle;
    std::ofstream handle1;
   Tmenu * first_menu;
    
public:
    TFile_handler();
    void change_handle();
    void change_handle1();
    void create_submenu(Tmenu* pointer_to_working_menu);
    void expand_submenu(Tmenu** pointer_to_working_menu,std::string key);
    void create_function(Tmenu* pointer_to_working_menu);
    void search_further(Tmenu** pointer_to_working_menu,std::string title);
    std::string get_name_of_the_file();
    void save_data_to_file(std::vector<TWindow> windows_to_save);
    Tmenu** get_data_from_file();
    std::string check_first_letter();
    char get_letter();
    void search_for_submenu(std::vector<TWindow> windows_to_save);
    void save_submenu(std::vector<TWindow> windows_to_save);
    
};
#endif
