#include "Main.hpp"
#include "Functions.hpp"
void Tfunction::do_something()
{
    std::cout<<"Greetings, this is "<<name<<my_number<<". I'm doing something very important."<<std::endl;
}
void Tfunction::increase_number()
{
    how_many++;
}
Tfunction::Tfunction()
{
    name = "Function nr";
    increase_number();
    my_number=how_many;
}
std::string Tfunction::tell_me_name()
{
    return name;
}
int Tfunction::give_me_number()
{
    return my_number;
}
