#include "Main.hpp"
#include "File_handler.hpp"
#include <stdio.h>
TFile_handler::TFile_handler()
{
    first_menu=new(Tmenu);
}

void TFile_handler::change_handle()
{
        char file_name[MAXLINE];
    try{
    std::cout<<"Please give me the name of your file: "<<std::endl;
       std::cin.get(file_name,MAXLINE-2);
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<int>::max(), '\n' );
       std::string path= "../files/"+static_cast<std::string>(file_name);
       handle.open(path);
       if(!handle.good()) throw ERROR;
       std::cout<<"Successfully opened file! :)"<<std::endl;
    }catch(int){
        handle.open(TExceptions::wrong_file_name());
        std::cout<<"Successfully opened file! :)"<<std::endl;
    }
}
void TFile_handler::get_data_from_file()
{
    Tmenu* pointer_to_working_menu=first_menu;
    std::string key;
   do{
    key=check_first_letter();
    if(key==new_window_key){
        char buff[new_window_key_size];
        handle.getline(buff, new_window_key_size);
    if(buff ==new_window_key){
        key=check_first_letter();
            if(key==title_window_key){
            std::string buff;
            getline(handle, buff,' ');
                if(buff == title_window_key){
                std::string title;
                getline(handle,title,'\n');
                Tmenu * pointer =pointer_to_working_menu->search_for_window(title);
                std::cout<<"SIALALALA"<<pointer->tell_me_name()<<std::endl;
        }
        }
    }
        
    }else if(key==menu_key){
    create_submenu(pointer_to_working_menu);
    }else if(key==function_key){
     create_function(pointer_to_working_menu);
    }
    }while(key!=exit_key);
    first_menu->draw_yourself();
}
std::string TFile_handler::check_first_letter()
{
    char c;
    try{
    handle>>c;
    if(!handle) throw ERROR;
    if(c =='N'){
        handle.unget();
        return new_window_key;
    }else if(c=='M'){
        handle.unget();
        return menu_key;
    }else if(c=='F'){
        handle.unget();
        return function_key;
    }else if (c=='X'){
        handle.unget();
        return exit_key;
    }else if(c=='T'){
        handle.unget();
        return title_window_key;
    }else{c='E'; throw ERROR;}
    }
    catch(int){
        handle.open(TExceptions::wrong_data_in_the_file());
        check_first_letter();
    }
    return "ERROR";
}
void TFile_handler::get_letter()
{
    char c= handle.get();
    std::cout<<c<<std::endl;
}
void TFile_handler::create_function(Tmenu * pointer_to_working_menu)
{
    char buff[function_key_size];
    handle.getline(buff, function_key_size);
    if(buff ==function_key){
        pointer_to_working_menu->create_window_with_function();
    }
}
void TFile_handler::create_submenu(Tmenu* pointer_to_working_menu)
{
        std::string buff;
        getline(handle, buff,' ');
    if(buff == menu_key){
        std::string name;
       getline(handle,name, '\n');
       pointer_to_working_menu->create_window_with_submenu(name);
    }
        
}
