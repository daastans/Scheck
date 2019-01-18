#include"parser.h"
#include"error.h"

using std::istream;
using std::string;

Parser::Parser(istream& is):mIn(is),mLineNo(0) {}    // You cannot assign istream values so initializer list is used

unsigned int Parser::LineNo() const {return mLineNo;}
string Parser::Context() const {return mLine;}
string Parser::NextWord()
{
    string word;
    if(mIs>>word) return word;
    else if(mIs.eof())
    {
        if(ReadLine()) return NextWord();
        else return "";
    }

    else throw ScheckError("Read Error");
}
bool Parser::ReadLine()
{
    if(getline(mIn,mLine))
    {
        mIs.clear();
        mIs.str(mLine);
        mLineNo++;
        return true;
    }
    else if(mIn.eof()) return false;
    else ScheckError("Couldnt read Input Stream");
}
