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
