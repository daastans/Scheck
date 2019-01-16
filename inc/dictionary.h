#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include"error.h"

class Dictionary
{
private:
  std::set<std::string> mWords;
public:
  Dictionary (const std:: string &fname)//const prevents unwated modifications
  {
    std::fstream wlist(fname.c_str());

    if(!wlist.is_open())
    {
        throw ScheckError("Error opening Dictionary "+fname);
    }

    std::string word;
    while(std::getline(wlist,word))
    {
      std::cout<<word<<std::endl;
      mWords.insert(word);
    }
    if(!wlist.eof())
    {
        throw ScheckError( "Error reading dictionary file " + fname );
    }
  }
  bool check (const std:: string &word)//passing by reference prevents copying overhead
  {
    std::cout<<"The word recieved "<<word<<std::endl;
    std::cout<<"iterator "<<&(*mWords.find(word))<<" End is "<<&(*mWords.end())<<std::endl;
    return mWords.find(word)!=mWords.end();
    //if word is not found find() func returns an iterator  which points to the end() of the set

  }
};
#endif
/*The include guards work like this: The first time dictionary.h is included,
 the macro INC_DICTIONARY_H is not defined,  so the #ifndef test succeeds, and the code following the
 #ifndef is processed by the compiler, which results in INC_DIRECTORY_H becoming defined.
 Then, the next time the the header file is included,
 the #ifndef test fails, and the code it controls is not compiled.*/
