#ifndef INC_PARSER_H
#define INC_PARSER_H
#include <iostream>
#include<string>
class Parser
{
private:
    std::istream& mSubmission;          //You cannot copy istream so you have to take it as reference although you caould have used pointer

public:
  Parser(std::istream &is);
  std::string NextWord();
  unsigned int LineNo() const;
  std::string Context() const;

};

#endif
