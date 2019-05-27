#include "Main.hpp"
#include "Menu.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Exceptions.hpp"
#include "Screen.hpp"
TKeyboard* Tmenu::My_keyboard=nullptr;

void Tmenu::add_empty_slot()
{
    TWindow empty_slot;
    Mywindows.push_back(empty_slot);
}
void Tmenu::assign_function_to_empty_slot()
{
 Mywindows[choose_slot()]=&Functions[choose_function()];   
}
void Tmenu::print_array()
{
    if(Functions.size()==0){
        std::cout<<"There is no functions to show!"<<std::endl;
        std::cout<<"HINT:Add some functions first."<<std::endl;
    }else
    {
    for(long unsigned int i=0;i<Functions.size();i++){
                std::cout<<i+1<<"."<<Functions[i]->tell_me_name()<<Functions[i]->give_me_number()<<std::endl;
    }
}
}
int Tmenu::choose_function()
{
    long unsigned int number;
    try{
    std::cout<<"Do you want to create new function?"<<std::endl;
    if(get_ans()){
        return create_new_function()->give_me_number()-1;
    }else{
        std::cout<<"Please, choose one:"<<std::endl;
        print_array();
        number = get_int(Functions.size());
    }
    }
    catch(int){
        number=TExceptions::bad_int_data(Functions.size());
    }
    return number-1;
}

void Tmenu::assign_menu_to_empty_slot()
{
    Tmenu *empty_menu=new(Tmenu);
    empty_menu->name=get_name();
    empty_menu->My_ancestor= this;
    empty_menu->give_me_my_keyboard(My_keyboard);
    Mywindows[choose_slot()]=&empty_menu;
}
void Tmenu::draw_yourself()
{
    if(Mywindows.size()>0){
for(long unsigned int i =0; i<Mywindows.size(); i++){
    Mywindows[i].draw_yourself();
}
    }else{
std::cout<<"This menu is empty."<<std::endl;
std::cout<<"HINT:Assign something to this menu."<<std::endl;
}
}
void Tmenu::expand_submenu()
{
    int which_one;
    try{
    std::cout<<"Choose submenu you want to expand:"<<std::endl;
    which_one=get_int(Mywindows.size());
    }
    catch(int){
        which_one=TExceptions::bad_int_data(Mywindows.size());
    }
    if(!Mywindows[which_one-1].is_submenu()){
        std::cout<<"This is not a submenu, you canot expand it!"<<std::endl;
    }else{
        My_successor=Mywindows[which_one-1].give_me_submenu_pointer();
        My_keyboard->change_keyboard(My_successor);
        My_successor->draw_yourself();
    }
    
}
void Tmenu::fold_submenu()
{
    if(My_ancestor!=nullptr){
        My_keyboard->change_keyboard(My_ancestor);
    }else{
        std::cout<<"Cannot fold a submenu! This is your first menu."<<std::endl;
    }
}
void Tmenu::remove_slot()
{
    long unsigned int which_one;
    try{
    std::cout<<"Choose which one of the windows you want to delete:"<<std::endl;
    which_one=get_int(Mywindows.size());
    }
    catch(int){
        which_one= TExceptions::bad_int_data(Mywindows.size());
    }
    if(!Mywindows[which_one].is_empty()){
        std::cout<<"This window contains data! Are you sure you want to delete it?"<<std::endl;
        if(get_ans()){
            Mywindows[which_one].remove_data();
            Mywindows.erase(Mywindows.begin()+which_one-1);///Musimy odjąć jedynkę ponieważ Mywindows.begin wskazuje na pierwszy element, gdybyśmy nie odejmowali tej jedynki to usuwalibyśmy element za tym odpowiednim
        }
    }else{
      Mywindows.erase(Mywindows.begin()+which_one-1);  
    }
}
void Tmenu::remove_data()
{
    for(unsigned int i=0; i<Functions.size();i++){
        delete (Functions[i]);
    }
    for(unsigned int i=0;i<Mywindows.size();i++){
        Mywindows[i].remove_data();
    }
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
int Tmenu::get_int( unsigned int limit)
{
      unsigned int liczba1;
    try{    
        std::cin>>liczba1;
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        if(!std::cin || liczba1>limit || liczba1<=0)
            throw ERROR;
    }
    catch(int ERROR){
        return TExceptions::bad_int_data(limit);
    }
    return liczba1;
}
int Tmenu::choose_slot()
{
    std::cout<<"Please choose an empty slot."<<std::endl;
    try{
    long unsigned int result = get_int(Mywindows.size());
        return result-1;
}
    catch(int){
        return TExceptions::bad_int_data(Mywindows.size())-1;
    }
}
TFunction* Tmenu::create_new_function()
{
    TFunction *new_function=new(TFunction);
    Functions.push_back(new_function);
    return new_function;
}
std::string Tmenu::get_name()
{
    char name[MAXLINE-2];
    try{
    std::cout<<"How would you like to name your submenu?"<<std::endl;
       std::cin.get(name,MAXLINE-2);
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<int>::max(), '\n' );
    if(!std::cin || !TExceptions::checking_string(name))
        throw ERROR;
    }
    catch(int){
    return TExceptions::bad_string();
    }
    return name;
}
void Tmenu::make_choice()
{
    int which_one;
    try{
    std::cout<<"Which window you want to choose?"<<std::endl;
    which_one=get_int(Mywindows.size());
    }
    catch(int){
        which_one=TExceptions::bad_int_data();
    }
    Mywindows[which_one-1].do_something();//Musimy odjąć jedynkę bo indeksowanie zaczyna się od zera
}
void Tmenu::give_me_my_keyboard(TKeyboard* new_keyboard)
{
    My_keyboard=new_keyboard;
}
void Tmenu::create_window_with_function()
{
    Mywindows.push_back(TWindow(create_new_function()));
}
void Tmenu::create_window_with_submenu(std::string name)
{
    Tmenu *empty_menu=new(Tmenu);
    empty_menu->name=name;
    empty_menu->My_ancestor= this;
    empty_menu->give_me_my_keyboard(My_keyboard);
    Mywindows.push_back(empty_menu);
}
Tmenu* Tmenu::search_for_window(std::string title)
{
    for(std::vector<TWindow>::iterator i=Mywindows.begin(); i!=Mywindows.end();i++){
        if(i->tell_me_name()==title){
         return i->give_me_submenu_pointer();
        }
    }
    return nullptr;
}

