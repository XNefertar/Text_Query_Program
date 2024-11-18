#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <format>


class TextQuery
{
private:
    std::vector<std::string> _FileContent;
    std::map<std::string, std::set<int>> _WordSetMap;

public:
    TextQuery(std::ifstream &FileContent)
    {
        std::string str;
        while(getline(FileContent, str)){
            _FileContent.push_back(str);
            std::istringstream StringStr(str);
            std::string word;
            while(StringStr >> word){
                _WordSetMap[word].insert(_FileContent.size());
            }
        }
        std::cout << "Read Test..." << std::endl;
        std::cout << "_FileContent size = " << _FileContent.size() << std::endl;
        std::cout << "_WordSetMap size = " << _WordSetMap.size() << std::endl;

    }

    std::string Query(std::string &TextToQuery)
    {
        std::set<int> LineSet = _WordSetMap[TextToQuery];
        // 构造应答字符串
        std::stringstream response;
        response << "The word \"" << TextToQuery << "\" appears in lines " << LineSet.size() << " times" << std::endl\
        << "The specific location of the occurrence # " << std::endl;
        for(auto index : LineSet){
            response << _FileContent[index - 1] << std::endl;
        }
        return response.str();
    }
};