#include <iostream>
#include<string>
#include "dictionary.h"
#include "parser.h"


int main() {
    try
    {
        std::cout << "scheck version 0.1\n" <<std::endl;
        Dictionary d("data/mydict.data");
        std::string word;

        std::ifstream sub("data/sub1.txt");

        if(!sub.is_open()) throw ScheckError("cannot open data/sub1.txt");

        Parser p(sub);

        while((word=p.NextWord())!="")
        {
            if(d.check(word))
            {std::cout<<word<<" is okay"<<std::endl;}
            else
            {std::cout<<word<<" is Misspelled at "<<p.LineNo()<<std::endl;}
        }
    }
    catch (const ScheckError &e)
    {
        std::cerr <<" Error "<<e.what()<< "\n";
    }



}
