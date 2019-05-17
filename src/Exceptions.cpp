#include "Main.hpp"
#include "Exceptions.hpp"
int TExceptions::bad_int_data()
{
    increase_number();
    int number1;
    do{
    std::cout<<"Seems you've entered bad data. Please try once again.(enter a digit)";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    std::cin>>number1;
    }while(!isdigit(number1));
    return number1;
}
void TExceptions::increase_number()
{
    how_many_times++;
}
int TExceptions::how_many()
{
    return how_many_times;
}
