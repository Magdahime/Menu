#include "Main.hpp"
#include "Exceptions.hpp"
#include <cstring>
#include <fstream>
int TExceptions::bad_int_data(int limit)
{
    increase_number();
    int number1;
    do{
    std::cout<<"Seems you've entered bad data. Please try once again.(enter a digit)";
    std::cin>>number1;
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    }while(!std::cin && number1>limit && number1<=0);
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
std::string TExceptions::bad_string()
{
    increase_number();
    char name[MAXLINE-2];
    do{
    std::cout<<"Seems you've entered bad data. Please try once again.(enter a proper string)"<<std::endl;
    std::cin.get(name, MAXLINE-2);
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    }while(!checking_string(name));
    return name;
}
bool TExceptions::checking_string(char* suspicious_string)
{
    for(long unsigned int i=0;i<strlen(suspicious_string);i++){
        if(!isalnum(suspicious_string[i]))
            return false;
    }
    return true;
}
std::string TExceptions::wrong_file_name()
{   
    std::ifstream handle;
    increase_number();
    char file_name[MAXLINE];
    std::string path;
    do{
    std::cout<<"Please try once again.(enter name of the file)"<<std::endl;
    std::cin.get(file_name,MAXLINE);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n' );
    path= "../files/"+static_cast<std::string>(file_name);
    handle.open(path);
    }while(!handle.good());
    handle.close();
    return path;
}
std::string TExceptions::wrong_data_in_the_file()
{
    std::cout<<"I'm afraid the data in the file are incorrect. "<<std::endl;
    return wrong_file_name();
}
