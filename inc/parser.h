#ifndef INC_PARSER_H
#define INC_PARSER_H
#include<sstream>
#include <iostream>
#include<string>
class Parser
{
private:
    std::istream& mIn;          //You can't copy, take it as reference OR pointer
    bool ReadLine();
    char NextChar();
    enum State {stInSpace,stInWord,stInNum};
    State mState;
    std::string mLine;
    unsigned int mLineNo,mPos;
    std::istringstream mIs;
public:
  Parser(std::istream &is);
  std::string NextWord();
  unsigned int LineNo() const;
  std::string Context() const;


};

#endif
