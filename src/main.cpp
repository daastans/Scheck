#include <iostream>
#include<string>
#include "dictionary.h"


int main() {
    try
    {
        std::cout << "scheck version 0.1" <<std::endl;
        Dictionary d("data/mydict.data");
        std::string word;

        while(getline(std::cin,word))
        {
            if(d.check(word))
            {std::cout<<word<<" is okay\n"<<std::endl;}
            else
            {std::cout<<word<<" is Misspelled\n"<<std::endl;}
        }
    }
    catch (const ScheckError &e)
    {
        std::cerr <<" Error "<<e.what()<< "\n";
    }



}
