#include"parser.h"
#include"error.h"

using std::istream;
using std::string;

Parser::Parser(istream& is):mIn(is),mLineNo(0),mPos(0),mState(stInSpace) {}    // You cannot assign istream values so initializer list is used

unsigned int Parser::LineNo() const {return mLineNo;}
string Parser::Context() const {return mLine;}
string Parser::NextWord()
{
    string word;

    while(char c=NextChar())
    {
        switch(mState)
        {
        case stInSpace:
            if(std::isalpha(c))
            {
                word+=c;
                mState=stInWord;
            }
            else if(std::isdigit(c))
            {
                mState=stInNum;
            }
            break;
        case stInWord:
            if(std::isalpha(c)||c=='\'')
                {
                    word+=c;
                }
            else if(std::isdigit(c))
                mState=stInNum;
            else
            {
                mState=stInSpace;
                return word;
            }
        case stInNum:
            {
                if(std::isalnum(c)||c=='\'')
                    word+=c;
                else
                {
                    mState=stInSpace;
                    word="";
                }
        default: throw ScheckError("State Error");
            }
        }
    }


}
bool Parser::ReadLine()
{
    if(getline(mIn,mLine))
    {
        mPos=0;
        mLine+=" ";
        mIs.clear();
        mIs.str(mLine);
        mLineNo++;
        return true;
    }
    else if(mIn.eof()) return false;
    else ScheckError("Couldnt read Input Stream");
}
char Parser::NextChar()
{
    if(mPos>=mLine.size())
    {
        if(!ReadLine())
            return 0;
        return mLine[mPos++];
    }
}
