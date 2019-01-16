#include <iostream>
#include<string>
#include "dictionary.h"


int main() {
    std::cout << "scheck version 0.1" <<std::endl;
    Dictionary d("data/mydict.data");
    std::string word;

    while(getline(std::cin,word))
    {
        if(d.check(word))
        {std::cout<<word<<" is okay"<<std::endl;}
        else
        {std::cout<<word<<" is Misspelled"<<std::endl;}
    }


}
