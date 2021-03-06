#include "Main.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"
#include "Functions.hpp"
#include "Exceptions.hpp"
#include "Screen.hpp"
#include "File_handler.hpp"
int TFunction::how_many=0;
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
void test9();
void test10();
void test11();
int main(void){
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    //test10();
    test11();
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
    TFunction fun1;
    TFunction fun2;
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
    TFunction fun1;
    TFunction fun2;
    TWindow window1;
    TWindow window2;
    std::cout<<"Double assigning to one window (functions) - expecting result: not possible"<<std::endl;
    window1=&fun1;
    window1=&fun2;
    std::cout<<"This window now shold not be empty."<<std::endl;
    std::cout<<window1.is_empty()<<std::endl;
    std::cout<<"Checking what is inside this window"<<std::endl;
    window1.draw_yourself();
    std::cout<<"Double assigning to one window (menu)- expecting result: not possible"<<std::endl;
    TWindow window3;
    Tmenu menu1;
    Tmenu menu2;
    window3=&menu1;
    window3=&menu2;
    std::cout<<"This window now shold not be empty."<<std::endl;
    std::cout<<window3.is_empty()<<std::endl;
    std::cout<<"This window is empty."<<std::endl;
    std::cout<<window2.is_empty()<<std::endl;
     std::cout<<"Double assigning to one window (menu+function)- expecting result: not possible"<<std::endl;
    window2=&fun2;
    window2=&menu2;
    std::cout<<"End of the test4."<<std::endl;
    pause();
}
void test5()
{
    std::cout<<"Start test5: New methods to class TMenu."<<std::endl;
    Tmenu menu1;
    std::cout<<"Adding 3 empty slots"<<std::endl;
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    std::cout<<"How this menu looks."<<std::endl;
    menu1.draw_yourself();
    std::cout<<"An empty menu-how it looks"<<std::endl;
    Tmenu menu2;
    menu2.draw_yourself();
    std::cout<<"Creating new functions"<<std::endl;
    menu1.create_new_function();
    menu1.create_new_function();
    std::cout<<"Functions of my menu1"<<std::endl;
    menu1.print_array();
    std::cout<<"End of the test5."<<std::endl;
    pause();
}
void test6()
{
    std::cout<<"Start test6: Getting data and exceptions."<<std::endl; 
    Tmenu menu1;
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    menu1.add_empty_slot();
    std::cout<<"Trying to show an empty array Function"<<std::endl;
    menu1.print_array();
    std::cout<<"Assigning function to empty slots"<<std::endl;
    menu1.draw_yourself();
    menu1.assign_function_to_empty_slot();
    menu1.draw_yourself();
    menu1.assign_function_to_empty_slot();
    menu1.draw_yourself();
    std::cout<<"End of the test6."<<std::endl;
    pause();
}
void test7()
{
     std::cout<<"Start test7: Assigning and creating submenu."<<std::endl;
     Tmenu menu1;
     menu1.add_empty_slot();
     menu1.add_empty_slot();
     menu1.add_empty_slot();
     menu1.add_empty_slot();
     menu1.add_empty_slot();
     std::cout<<"That's how it looks like without any functions or submenu"<<std::endl;
     menu1.draw_yourself();
     menu1.assign_menu_to_empty_slot();     
     std::cout<<"That's how it looks after assigning first submenu"<<std::endl;
     menu1.draw_yourself();
     menu1.assign_menu_to_empty_slot();
     std::cout<<"That's how it looks after assigning second submenu"<<std::endl;
     menu1.draw_yourself();
     std::cout<<"End of the test7."<<std::endl;
     pause();
}
void test8()
{
   std::cout<<"Start test8: Removing slots."<<std::endl; 
   Tmenu menu1;
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   std::cout<<"This is how looks this menu before removing:"<<std::endl;
   std::cout<<"We will now assign some data to it."<<std::endl;
   menu1.draw_yourself();
   menu1.assign_function_to_empty_slot();
   menu1.draw_yourself();
   menu1.assign_menu_to_empty_slot();
   menu1.draw_yourself();
   menu1.assign_function_to_empty_slot();
   menu1.draw_yourself();
   std::cout<<"Time for removal!(3 times)"<<std::endl;
   menu1.draw_yourself();
   menu1.remove_slot();
   menu1.draw_yourself();
   menu1.remove_slot();
   menu1.draw_yourself();
   menu1.remove_slot();
   menu1.draw_yourself();
   std::cout<<"End of the test8."<<std::endl;
   pause();
}
void test9()
{
     std::cout<<"Start test9: Making choices in our menu."<<std::endl; 
   Tmenu menu1;
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   menu1.add_empty_slot();
   std::cout<<"This is how it looks before assigning. We will now try to assign a submenu and a function."<<std::endl;
   menu1.draw_yourself();
   menu1.assign_function_to_empty_slot();
   menu1.assign_menu_to_empty_slot();
   menu1.draw_yourself();
   std::cout<<"Now, we are making three choices to check how our program will behave."<<std::endl;
   menu1.make_choice();
   menu1.make_choice();
   menu1.make_choice();
   std::cout<<"End of the test9."<<std::endl;
   pause();
}

void test10()
{
    std::cout<<"Start test10: Folding and expanding submenu."<<std::endl; 
    TScreen screen;
    std::cout<<"End of the test10."<<std::endl;
    pause();
}
void test11()
{
    std::cout<<"Start test11: Testing out new class TFile_handler."<<std::endl; 
    TFile_handler handler;
    handler.change_handle();
    handler.get_data_from_file();
    std::cout<<"End of the test11."<<std::endl;
    pause();
}

