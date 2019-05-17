#include "Main.hpp"
#include "Keyboard.hpp"
#include "Exceptions.hpp"
void TKeyboard::show_me_the_list()
{
    std::cout.width(MAXLINE);
    std::cout<<stars<<std::endl;
    std::cout<<"Full list of commands: "<<std::endl;
    for(auto i = commands_list.begin(); i<commands_list.end(); i++){
        std::cout<<"-"<<*i<<std::endl;
    }
    std::cout<<stars<<std::endl;
    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<stars<<std::endl;
    std::cout<<"How to make a full command?"<<std::endl;
    std::cout<<"<one of the list above>"<<std::endl;
    std::cout<<stars<<std::endl;
    std::cout<<std::endl<<std::endl<<std::endl;
}
void TKeyboard::get_command()
{
    while(true){
        std::string command;
        std::cout<<"Waiting for your command..."<<std::endl;
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
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(2):{
            std::cout<<commands_list[choice]<<std::endl;
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
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(6):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(7):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(8):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(9):{
            std::cout<<commands_list[choice]<<std::endl;
        break;
    }
        case(10):{
            std::cout<<commands_list[choice]<<std::endl;
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

