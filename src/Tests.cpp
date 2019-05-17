#include "Main.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"
#include "Functions.hpp"

void pause();
void test1();
void test2();
void test3();
void test4();
int main(void){
    test1();
    test2();
    test3();
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

