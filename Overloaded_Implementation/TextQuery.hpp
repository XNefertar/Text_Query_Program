#include <stdio.h>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <format>
#include "QueryResult.hpp"



// 预处理输入
class TextQuery
{
private:
    std::vector<std::string> _FileContent;
    std::map<std::string, std::shared_ptr<std::set<int>>> _WordSetMap;
public:
    // 输入读取并处理
    // 建立单词 -> 行号的映射
    void TextQueryInit(std::ifstream &FileContent)
    {
        std::string str;
        while(getline(FileContent, str)){
            _FileContent.push_back(str);
            std::istringstream StringStr(str);
            std::string word;
            while(StringStr >> word){
                _WordSetMap[word]->insert(_FileContent.size());
            }
        }
    }

    QueryResult query(const std::string& word){
        std::shared_ptr<std::set<int>> lineptr = _WordSetMap[word];
        
    }
};