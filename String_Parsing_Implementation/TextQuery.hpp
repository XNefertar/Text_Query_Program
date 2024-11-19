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

// 策略模式 TODO

class TextQuery
{
protected:
    std::vector<std::string> _FileContent;
    std::map<std::string, std::set<int>> _WordSetMap;

public:
    TextQuery() = default;

    void TextQueryInit(std::ifstream &FileContent)
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
    }

    virtual std::string Query(std::string &TextToQuery) = 0;
};

class WordQuery
:public TextQuery
{
public:
    std::string Query(std::string &TextToQuery) override
    {
        std::set<int> LineSet = _WordSetMap[TextToQuery];
        // 构造应答字符串
        std::stringstream response;
        response << "Excuting Query for: " << TextToQuery << std::endl \
        << "The word \"" << TextToQuery << "\" occurs " << LineSet.size() << " times" << std::endl;
        for(auto index : LineSet){
            response << "(" << "line " << index << ") " << _FileContent[index - 1] << std::endl;
        }
        return response.str();
    }
};

class BinaryQuery
:public TextQuery
{
public:
    virtual std::string Query(std::string){}
    virtual std::string Query(std::string &TextToQuery1, std::string &TextToQuery2) = 0;
};

class NotQuery
:public BinaryQuery
{
public:
    std::string Query(std::string &TextToQuery) override
    {
        std::set<int> LineSet = _WordSetMap[TextToQuery];
        int n = _FileContent.size();
        std::set<int> NotLineSet;
        for(int i = 1; i <= n; ++i){
            auto it = LineSet.find(i);
            if(it == LineSet.end())
                NotLineSet.insert(i);
        }

        // 构造应答字符串
        std::stringstream response;
        response << "Excuting Query for: " << TextToQuery << " Not in Text" << std::endl;
        for(auto index : NotLineSet){
            response << "(" << "line " << index << ") " << _FileContent[index - 1] << std::endl;
        }
        return response.str();
    }
};

class OrQuery
:public BinaryQuery
{
public:
    std::string Query(std::string &TextToQuery1, std::string &TextToQuery2) override
    {
        

    }


};

class AndQuery
:public BinaryQuery
{
public:
    std::string Query(std::string &TextToQuery1, std::string &TextToQuery2) override
    {

    }
};