#include <fstream>
#include "TextQuery.hpp"

static void Usage(std::string reponse)
{
    std::cout << reponse << "\t" << "File Path + Word " << std::endl << std::endl;
}

int main(int argc, char* argv[])
{
    if(argc <= 2){
        Usage(argv[0]);
    }


    return 0;
}