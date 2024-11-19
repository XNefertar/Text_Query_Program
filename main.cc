#include <fstream>
#include "TextQuery.hpp"

void RunTextQuery(std::ifstream &Text, TextQuery* TextMethod){
    TextMethod->TextQueryInit(Text);
    for(;;){
        std::cout << "Please enter the word you want to query # " << std::endl;
        std::string s;
        if(!(std::cin >> s) || s == "q"){
            break;
        }
        std::cout << TextMethod->Query(s) << std::endl;
    }
}

int main()
{
    std::ifstream File("./example.txt");
    if (!File.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    std::cout << "Open Success." << std::endl;
    WordQuery wq;
    NotQuery nq;
    RunTextQuery(File, &nq);

    return 0;
}