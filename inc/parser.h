#ifndef INC_PARSER_H
#define INC_PARSER_H
#include<sstream>
#include <iostream>
#include<string>
class Parser
{
private:
    std::istream& mIn;          //You cannot copy istream so you have to take it as reference although you caould have used pointer
    bool ReadLine();
    std::string mLine;
    unsigned int mLineNo;
    std::istringstream mIs;
public:
  Parser(std::istream &is);
  std::string NextWord();
  unsigned int LineNo() const;
  std::string Context() const;

};

#endif
