#include "Main.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Menu.hpp"
void TWindow::do_something()
{
    if(function!=nullptr)
        function->do_something();
}
void TWindow::draw_yourself()
{
    if(submenu!=nullptr){
        submenu->draw_yourself();
    }else if (function!= nullptr){
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill(' ');
        std::cout<<"**"<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill(' ');
        std::cout<<"*"<<function->tell_me_name()<<"*"<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill(' ');
        std::cout<<"**"<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
    }else{
        std::cout<<"Nothing is assigned to this window!"<<std::endl<<"HINT: Assign something to this window first."<<std::endl;
    }
}

