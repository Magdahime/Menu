#include "Main.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Exceptions.hpp"
int Tfunction::how_many=0;
int TExceptions::how_many_times=0;
void pause();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
int main(void){
    //test1();
    //test2();
    test3();
    test4();
    return 0;
}
void pause()
{
    std::cout<<"Please press any key to continue..."<<std::endl;
    getchar();
}

void test1()
{
    std::cout<<"Start test1: Showing command list."<<std::endl;
    TKeyboard Keyboard;
    Keyboard.show_me_the_list();
    std::cout<<"End of the test1."<<std::endl;
    pause();
    
}
void test2()
{
    std::cout<<"Start test2: Getting commands from keyboard."<<std::endl;
    TKeyboard Keyboard;
    Keyboard.get_command();
    std::cout<<"End of the test2."<<std::endl;
    pause();
}
void test3()
{
    std::cout<<"Start test3: Testing class TWindow and TFunction."<<std::endl;
    Tfunction fun1;
    Tfunction fun2;
    TWindow window1(&fun1);
    TWindow window2(&fun2);
    TWindow window3;
    std::cout<<"WINDOW1 - with function."<<std::endl;
    window1.do_something();
    window1.draw_yourself();
    std::cout<<"WINDOW2 - with second function."<<std::endl;
    window2.do_something();
    window2.draw_yourself();
    std::cout<<"WINDOW3 -uninitialized."<<std::endl;
    window3.do_something();
    window3.draw_yourself();
    std::cout<<"End of the test3."<<std::endl;
    pause();
}
void test4()
{
    std::cout<<"Start test4: New methods to class TWindow."<<std::endl;
    Tfunction fun1;
    Tfunction fun2;
    TWindow window1;
    TWindow window2;
    std::cout<<"Double assigning to one window (functions) - expecting result: not possible"<<std::endl;
    window1=fun1;
    window1=fun2;
    std::cout<<"This window now shold not be empty."<<std::endl;
    std::cout<<window1.is_empty()<<std::endl;
    std::cout<<"Checking what is inside this window"<<std::endl;
    window1.draw_yourself();
    std::cout<<"Double assigning to one window (menu)- expecting result: not possible"<<std::endl;
    TWindow window3;
    Tmenu menu1;
    Tmenu menu2;
    window3=menu1;
    window3=menu2;
    std::cout<<"This window now shold not be empty."<<std::endl;
    std::cout<<window3.is_empty()<<std::endl;
    std::cout<<"This window is empty."<<std::endl;
    std::cout<<window2.is_empty()<<std::endl;
     std::cout<<"Double assigning to one window (menu+function)- expecting result: not possible"<<std::endl;
    window2=fun2;
    window2=menu2;
    std::cout<<"End of the test4."<<std::endl;
    pause();
}
void test5()
{
    std::cout<<"Start test4: New methods to class TWindow."<<std::endl;
    std::cout<<"End of the test4."<<std::endl;
    pause();
}


