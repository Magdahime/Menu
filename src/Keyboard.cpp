#include "Main.hpp"
#include "Keyboard.hpp"
int TKeyboard::check(std::string command)
{
     for(auto i = commands_list.begin(); i<commands_list.end(); i++){
         
    }
}
void TKeyboard::show_me_the_list()
{
    std::cout.width(MAXLINE);
    std::cout<<stars<<std::endl;
    std::cout<<"Full list of commands: "<<std::endl;
    for(auto i = commands_list.begin(); i<commands_list.end(); i++){
        std::cout<<"-"<<*i<<std::endl;
    }
    std::cout<<stars<<std::endl; 
}
void TKeyboard::choose()
{
}
void TKeyboard::get_command()
{
    while(true){
        std::string command;
        std::cout<<"Waiting for your command..."<<std::endl;
        std::getline(std::cin, command);
        
    }
}
