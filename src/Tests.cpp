#include "Main.hpp"
#include "Keyboard.hpp"
void pause();
void test1();
void test2();
int main(void){
    test1();
    test2();
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

