#include "Main.hpp"
#include "Keyboard.hpp"
#include "Exceptions.hpp"
void TKeyboard::show_me_the_list()
{
    std::cout.width(MAXLINE);
    std::cout<<stars<<std::endl;
    std::cout<<"Full list of commands: "<<std::endl;
    for(std::array<std::string,COMMANDS>::iterator i=commands_list.begin(); i!=commands_list.end();i++){
        std::cout<<*i<<"   ";
    }
    std::cout<<std::endl<<stars<<std::endl;
}
void TKeyboard::get_command()
{
    while(true){
        My_menu->draw_yourself();
        std::string command;
        std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        std::cout<<"Waiting for your command..."<<std::endl;
        std::cout<<"If you need assistance, please type help."<<std::endl;
        show_me_the_list();
        getline(std::cin,command);
        int result =check(command);
        if(result!=ERROR)
        choose(result);
    }
}
int TKeyboard::check(std::string command)
{
    for(long unsigned int i=0; i<commands_list.size(); i++){
        if(commands_list[i]==command)
            return i;
    }
    std::cout<<"Your command is incorrect.If you need assistance, please use 'help'."<<std::endl;
    return ERROR;
}
void TKeyboard::choose(int choice)
{
    switch(choice){
        case(0):{
            show_me_the_list();
        break;
    }
        case(1):{
            My_menu->add_empty_slot();
                    clrscrs();
        break;
    }
        case(2):{
           My_menu->remove_slot();
                   clrscrs();
        break;
    }
        case(3):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(4):{
           std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(5):{
            My_menu->assign_menu_to_empty_slot();
                    clrscrs();
        break;
    }
        case(6):{
            My_menu->remove_slot();
                    clrscrs();
        break;
    }
        case(7):{
            My_menu->assign_function_to_empty_slot();
                    clrscrs();
        break;
    }
        case(8):{
            My_menu->expand_submenu();
                    clrscrs();
        break;
    }
        case(9):{
           My_menu->fold_submenu();
                   clrscrs();
        break;
    }
        case(10):{
            My_menu->make_choice();
        break;
    }
        case(11):{
           std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(12):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(13):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
           
        case(14):{
        exit(0);
        break;
    }
        case(15):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
}
    
}
int TKeyboard::get_int()
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
void TKeyboard::change_keyboard(Tmenu* new_menu)
{
    std::cout<<this<<std::endl;
    My_menu=new_menu;
}

void TKeyboard::clrscrs()
{
            system("@cls||clear");
}
