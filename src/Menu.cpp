#include "Main.hpp"
#include "Menu.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Exceptions.hpp"
void Tmenu::add_empty_slot()
{
    TWindow empty_slot;
    Mywindows.push_back(empty_slot);
}
void Tmenu::assign_function_to_empty_slot()
{
 Mywindows[choose_slot()]=Functions[choose_function()];   
}
void Tmenu::print_array()
{
    for(long unsigned int i=0;i<Functions.size();i++){
                std::cout<<i+1<<"."<<Functions[i].tell_me_name()<<std::endl;
}
}
void Tmenu::assign_menu_to_empty_slot()
{
    Tmenu empty_menu;
    Mywindows[choose_slot()]=empty_menu;
}
void Tmenu::draw_yourself()
{
    if(Mywindows.size()>0){
for(long unsigned int i =0; i<Mywindows.size(); i++){
    Mywindows[i].draw_yourself();
}}else
std::cout<<"This menu is empty."<<std::endl;
std::cout<<"HINT:Assign something to this menu."<<std::endl;
}
void Tmenu::expand_submenu()
{
}
void Tmenu::fold_submenu()
{
}
void Tmenu::remove_empty_slot()
{
}
void Tmenu::remove_submenu()
{
}
std::string Tmenu::tell_me_name()
{
    return name;
}
bool Tmenu::get_ans()
{
char c;
(std::cin>>c).get();
if(c=='Y'|| c=='y'){
    return true;
}else if(c=='N' || c=='n')
    return false;
else {
    std::cout<<"Error, please try once again."<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    return get_ans();
}
}
int Tmenu::choose_function()
{
    std::cout<<"Do you want to create new function?"<<std::endl;
    if(get_ans()){
        if(Functions.size()==COMMANDS-1){
            std::cout<<"Unable to add new functions. Please choose one of the below:"<<std::endl;
           print_array();
           try{
               long unsigned int result = get_int();
               if(result>Functions.size()){
                   throw ERROR;
               }else 
                   return result-1;
        }
            catch(int ERROR){
            return TExceptions::bad_int_data();
                            }
        }else{
        Tfunction new_function;
        Functions[Functions.size()]=new_function;
        }
    }else{
        std::cout<<"Please choose one of the below:"<<std::endl;
        print_array();
        try{
    long unsigned int result=get_int();
    if(result>Functions.size()){
        throw ERROR;
    }else
        return result-1;
        }
    catch(int ERROR){
    return TExceptions::bad_int_data();
    }
}
return ERROR;
}
int Tmenu::get_int()
{
      unsigned int liczba1;
    try{    
        std::cin>>liczba1;
        if(!isdigit(liczba1))
            throw ERROR;
    }
    catch(int ERROR){
        return TExceptions::bad_int_data();
    }
    return liczba1;
}
int Tmenu::choose_slot()
{
    std::cout<<"Please choose an empty slot."<<std::endl;
    try{
    long unsigned int result = get_int();
    if(result>Mywindows.size()){
        throw ERROR;
    }else
        return result-1;
}
    catch(int){
        return TExceptions::bad_int_data();
    }
}
