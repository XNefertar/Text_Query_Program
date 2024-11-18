#include <fstream>
#include "TextQuery.hpp"

void RunTextQuery(std::ifstream &Text){
    // Build Mapping TODO
    TextQuery tq(Text);
    for(;;){
        std::cout << "Please enter the word you want to query # " << std::endl;
        std::string s;
        if(!(std::cin >> s) || s == "q"){
            break;
        }
        // std::cout << "TEST ### " << s << "####" << std::endl;
        // Display Result TODO
        std::cout << tq.Query(s) << std::endl;
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
    RunTextQuery(File);

    return 0;
}