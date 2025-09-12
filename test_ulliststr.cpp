#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <iostream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])

{
    //std::cout << "start\n";
    ULListStr dat; 
    /// test all edge cases:

    // pop back from null 
    dat.pop_back(); 

    // pop front from null 
    dat.pop_front(); 

    // pushing back and front to null list
    dat.push_front("hellow");
    dat.push_back("goodbye"); 


    // push back 20 words (used random word generator to get the words ) 
    std::vector<std::string> fruits = { "apple", "banana", "cherry", "date", "elderberry",
        "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "papaya", "quince",
        "raspberry", "strawberry", "tangerine", "ugli", "vanilla"
        };
    for (size_t i = 0; i < 20; i++){
        dat.push_back(fruits[i]); 
    }
    // push front 15 words 
    std::vector<std::string> countries  = {
        "Afghanistan", "Algeria", "Belgium", "Chile", "Colombia", "Denmark", 
        "Finland", "Greece", "Indonesia", "Iran", "Ireland", "Kazakhstan",
         "Kenya", "Malaysia", "Norway", "Peru", "Poland", "Romania", "Sweden", "Thailand"
    };
    for (size_t i = 0 ; i < 15; i++){
        dat.push_front(countries[i]); 
    }

    // size should be 
    if (dat.size() == 37){
        std::cout << "good size" << std::endl; 
    }

    // get val at loc 14 
    // get val at loc 0 

    // get val at loc arrsize 

    // pop back last element in list

    // pop front last element in list 


    return 0;
}
