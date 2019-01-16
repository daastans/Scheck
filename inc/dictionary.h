#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include<iostream>
#include<string>

class Dictionary
{
public:
  Dictionary (const std:: string &fname){} //const prevents unwated modifications
  bool check (const std:: string &word)//passing by reference prevents copying overhead
  {
    return false;
  }
};
#endif
/*The include guards work like this: The first time dictionary.h is included,
 the macro INC_DICTIONARY_H is not defined,  so the #ifndef test succeeds, and the code following the
 #ifndef is processed by the compiler, which results in INC_DIRECTORY_H becoming defined.
 Then, the next time the the header file is included,
 the #ifndef test fails, and the code it controls is not compiled.*/
