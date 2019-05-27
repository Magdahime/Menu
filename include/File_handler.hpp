#ifndef FILE_HANDLER
#define FILE_HANDLER
#include "Main.hpp"
#include "fstream"
class TFile_handler{
private:
    std::ifstream handle;
public:
    void change_handle();
    void get_name_of_the_file();
    void save_data_to_file();
    void get_data_from_file();
    
};
#endif
