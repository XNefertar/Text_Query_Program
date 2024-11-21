#ifndef __CLASSQUERY_HPP__
#define __CLASSQUERY_HPP__

#include "TextQuery.hpp"
#include "QueryResult.hpp"

class Query
{

};


// abstract class
class Query_Base
{
public:
    virtual QueryResult eval(const TextQuery&) = 0;

};

// basic query
class WordQuery
: public Query_Base
{
public:
    virtual QueryResult eval(const TextQuery& str) override {
        
    }


};

// operator ~
class NotQuery
: public Query_Base
{


};

// 二元运算符
// operator &
// operator |
class BinaryQuery
: public Query_Base
{
private:
    Query _lhs;
    Query _rhs;
    std::string _opSym;
public:
    BinaryQuery(Query lhs, Query rhs, std::string opSym)
        : _lhs(lhs),
          _rhs(rhs),
          _opSym(opSym)
    {}


};

class AndQuery
: public BinaryQuery
{
public:



};

#endif //  __CLASSQUERY_HPP__