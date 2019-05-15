#include "Main.hpp"
#include "Functions.hpp"
void Tfunction::do_something()
{
    std::cout<<"Greetings, this is "<<name<<". I'm doing something very important."<<std::endl;
}
void Tfunction::increase_number()
{
    how_many++;
}
Tfunction::Tfunction()
{
    std::string first_part = "Function nr.";
    increase_number();
    name=first_part+static_cast<char>(how_many);
}
std::string Tfunction::tell_me_name()
{
    return name;
}
