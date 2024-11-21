#ifndef __QUERYRESULT_HPP__
#define __QUERYRESULT_HPP__

class QueryResult
{
private:
    std::shared_ptr<std::set<int>> _LinePtr;
    std::string _File;
    std::string _QueryString;

public:
    QueryResult(std::shared_ptr<std::set<int>> lineptr, std::string file, std::string querystring)
    : _LinePtr(lineptr),
      _File(file),
      _QueryString(querystring)
    {}

    // operator Print
    // TODO
};



#endif // __QUERYRESULT_HPP__