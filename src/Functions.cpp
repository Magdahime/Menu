#include "Main.hpp"
#include "Functions.hpp"
void TFunction::do_something()
{
    std::cout<<"Greetings, this is "<<name<<my_number<<". I'm doing something very important."<<std::endl;
}
void TFunction::increase_number()
{
    how_many++;
}
TFunction::TFunction()
{
    name = "Function nr";
    increase_number();
    my_number=how_many;
}
std::string TFunction::tell_me_name()
{
    return name;
}
int TFunction::give_me_number()
{
    return my_number;
}
int TFunction::give_me_static()
{
    return how_many;
}
