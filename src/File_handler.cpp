#include "Main.hpp"
#include "File_handler.hpp"
#include <stdio.h>
TFile_handler::TFile_handler()
{
    first_menu=new(Tmenu);
}

void TFile_handler::change_handle()
{
    try{
       handle.open(get_name_of_the_file());
       if(!handle.good()) throw ERROR;
       std::cout<<"Successfully opened file! :)"<<std::endl;
    }catch(int){
        handle.open(TExceptions::wrong_file_name());
        std::cout<<"Successfully opened file! :)"<<std::endl;
    }
}
void TFile_handler::change_handle1()
{
      try{
       handle1.open(get_name_of_the_file());
       if(!handle1.good()) throw ERROR;
       std::cout<<"Successfully opened file! :)"<<std::endl;
    }catch(int){
        handle1.open(TExceptions::wrong_file_name());
        std::cout<<"Successfully opened file! :)"<<std::endl;
    }  
}

std::string TFile_handler::get_name_of_the_file()
{
    std::string path;
    char file_name[MAXLINE];
    try{
    std::cout<<"Please give me the name of your file: "<<std::endl;
    std::cin.get(file_name,MAXLINE-1);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n' );
    if(!std::cin) throw ERROR;
    path= "../files/"+static_cast<std::string>(file_name);
    }
    catch(int){
          path=TExceptions::wrong_file_name();
    }
    return path;
}

Tmenu** TFile_handler::get_data_from_file()
{
    change_handle();
    Tmenu* pointer_to_working_menu=first_menu;
    std::string key;
   do{
    key=check_first_letter();
    if(key==new_window_key){
        expand_submenu(&pointer_to_working_menu,key);
    }else if(key==menu_key){
    create_submenu(pointer_to_working_menu);
    }else if(key==function_key){
     create_function(pointer_to_working_menu);
    }
    }while(key!=exit_key);
    handle.close();
    return &first_menu;
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
char TFile_handler::get_letter()
{
    char c= handle.get();
    handle.unget();
    return c;
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
void TFile_handler::expand_submenu(Tmenu** pointer_to_working_menu,std::string key)
{
        
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
                search_further(pointer_to_working_menu,title);
        }
        }else{
            if(get_letter()!='X')
            (*pointer_to_working_menu)->add_empty_slot();
        }
    } 
}
void TFile_handler::search_further(Tmenu** pointer_to_working_menu,std::string title)
{
    try{
    if(!(*pointer_to_working_menu)->search_for_window(title)){
        if((*pointer_to_working_menu)->back()==nullptr){
            std::cout<<"This file is corrupted.\n";
            (*pointer_to_working_menu)->remove_data();
            pointer_to_working_menu=&first_menu;
            throw ERROR;
        }
        *pointer_to_working_menu=(*pointer_to_working_menu)->back();
      search_further(pointer_to_working_menu,title);
    }else
        *pointer_to_working_menu=(*pointer_to_working_menu)->search_for_window(title);
    }catch(int){
        get_data_from_file();
    }
}

void TFile_handler::save_submenu(std::vector<TWindow> windows_to_save)
{
    for(std::vector<TWindow>::iterator i=windows_to_save.begin(); i!=windows_to_save.end(); i++){
        if(i->is_submenu()){
            handle1<<menu_key<<" "<<i->tell_me_name()<<std::endl;
        }else {
            if( !i->is_empty()){
           handle1<<function_key<<std::endl; 
        }else{
            handle1<<new_window_key<<std::endl;
        }
        }
    }
    handle1<<new_window_key<<std::endl;
    search_for_submenu(windows_to_save);
}
void TFile_handler::search_for_submenu(std::vector<TWindow> windows_to_save)
{
    for(std::vector<TWindow>::iterator i=windows_to_save.begin(); i!=windows_to_save.end(); i++){
        if(i->is_submenu()){
            handle1<<title_window_key<<" "<<i->tell_me_name()<<std::endl;
            save_submenu(*i->give_me_submenu_pointer()->send_data());
        }
    }
}
void TFile_handler::save_data_to_file(std::vector<TWindow> windows_to_save)
{
    
    change_handle1();
    if(windows_to_save.size()>0){
    for(std::vector<TWindow>::iterator i=windows_to_save.begin(); i!=windows_to_save.end(); i++){
        if(i->is_submenu()){
            handle1<<menu_key<<" "<<i->tell_me_name()<<std::endl;
        }else {
            if( !i->is_empty()){
           handle1<<function_key<<std::endl; 
        }else{
            handle1<<new_window_key<<std::endl;
        }
        }
    }
    handle1<<new_window_key<<std::endl;
    search_for_submenu(windows_to_save);
    handle1<<"X"<<std::endl;
    handle1.close();
    }else{
        std::cout<<"There is nothing to save... This submenu is empty."<<std::endl;
        std::cout<<"HINT:Try adding something to this menu."<<std::endl;
    }
}
