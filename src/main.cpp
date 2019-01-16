#include <iostream>
#include<string>
#include "dictionary.h"


int main() {
    std::cout << "scheck version 0.1" <<std::endl;
    Dictionary d("mydict.dat");
    std::string word="dog";
    if(d.check(word))
    {std::cout<<word<<"is okay"<<std::endl;}
    else
    {std::cout<<word<<" is Misspelled"<<std::endl;}

}
