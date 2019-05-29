#include "Main.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Menu.hpp"
void TWindow::do_something()
{
    if(function!=nullptr)
        function->do_something();
    else if (submenu!=nullptr)
        std::cout<<"I'm just a submenu I can't do anything :("<<std::endl;
    else
        std::cout<<"I'm just an empty window. I can't do anything :("<<std::endl;
}
void TWindow::draw_yourself()
{
        //do stworzenia ładnego obramowania okienka
        std::string free_space(MAXLINE-2,' ');
        std::string frame='*'+free_space+'*';
    if(submenu!=nullptr){
        int size=submenu->tell_me_name().size();
        std::string free_space2((MAXLINE-2-size)/2,' ');
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
        std::cout<<frame<<std::endl;
        if(size%2)
            std::cout<<"* "<<free_space2<<submenu->tell_me_name()<<free_space2<<"*"<<std::endl;
        else
        std::cout<<"*"<<free_space2<<submenu->tell_me_name()<<free_space2<<"*"<<std::endl; 
        std::cout<<frame<<std::endl;
        std::cout.width(MAXLINE);
        std::cout.fill('*');
        std::cout<<""<<std::endl;
    }else if (function!= nullptr){
        int size=function->tell_me_name().size()+2;
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
void TWindow::operator=(Tmenu** submenu1)
{
    if(is_empty()){
    submenu=*submenu1;
    }else 
        std::cout<<"Impossible to assign a submenu! This slot is already taken."<<std::endl;
}
void TWindow::operator=(TFunction* function1)
{
    if(is_empty()){
    function=function1;
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
void TWindow::remove_data()
{
    if(!is_submenu()){
        delete (function);
        function =nullptr;
    }
    else{
        submenu->remove_data();
        submenu = nullptr;
    }
    
}
bool TWindow::is_submenu()
{
    if(submenu!=nullptr)
        return true;
    return false;
}
Tmenu* TWindow::give_me_submenu_pointer()
{
    return submenu;
}
std::string TWindow::tell_me_name()
{
    if(!is_submenu()){
        return function->tell_me_name();
    }
    return submenu->tell_me_name();
}
