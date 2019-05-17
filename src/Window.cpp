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
        //do stworzenia ładnego obramowania okienka
        std::string free_space(MAXLINE-2,' ');
        std::string frame='*'+free_space+'*';
    if(submenu!=nullptr){
        submenu->draw_yourself();
    }else if (function!= nullptr){
        int size=function->tell_me_name().size();
        std::string free_space1((MAXLINE-2-size)/2,' ');
        //tworzymy okienko
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
        std::cout<<frame<<std::endl;
        std::cout<<"*"<<free_space1<<function->tell_me_name()<<function->give_me_number()<<free_space1<<"*"<<std::endl;
        std::cout<<frame<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
    }else if(function==nullptr || submenu==nullptr){
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
        std::cout<<frame<<std::endl;
        std::cout<<frame<<std::endl;
        std::cout<<frame<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
    }
}
void TWindow::operator=(Tmenu submenu1)
{
    if(is_empty()){
    submenu=&submenu1;
    }else 
        std::cout<<"Impossible to assign a submenu! This slot is already taken."<<std::endl;
}
void TWindow::operator=(Tfunction function1)
{
    if(is_empty()){
    function=&function1;
    }else{
        std::cout<<"Impossible to assign a function! This slot is already taken."<<std::endl;
    }
}
bool TWindow::is_empty()
{
    if(submenu==nullptr && function==nullptr)
        return true;
    return false;
}
