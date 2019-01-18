#include"parser.h"
#include"error.h"

using std::istream;
using std::string;

Parser::Parser(istream& is):mSubmission(is) {}    // You cannot assign istream values so initializer list is used

string Parser::NextWord()
{
    string word;
    if(mSubmission>>word) return word;
    else if(mSubmission.eof()) return "";
    else throw ScheckError("Read Error");
}
