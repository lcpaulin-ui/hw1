#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <iostream>

#include <map>
#include <cstdlib>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])

{
    //std::cout << "start\n";
    ULListStr dat; 
    /// test all edge cases:

//testing push back 

    ULListStr data; 
    // popped back from empty list 
    data.pop_back();
    data.pop_front();

    if (data.size() != 0){
        std::cout << "size should be 0, but it's " << dat.size()<< std::endl; 
    }

    // push to null
    dat.push_back("nullcase"); 

    // check size.
    size_t size = dat.size();
    if (size != 1){
        std::cout << "size should be 1, but it's " << size << std::endl; 
    }
    dat.pop_back();
    size = dat.size();
    //list empty
    if (size != 0){
        std::cout << "size should be 0, but it's " << size << std::endl; 
    }

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
    // push front 15 words , also used random 
    std::vector<std::string> countries  = {
        "Afghanistan", "Algeria", "Belgium", "Chile", "Colombia", "Denmark", 
        "Finland", "Greece", "Indonesia", "Iran", "Ireland", "Kazakhstan",
         "Kenya", "Malaysia", "Norway", "Peru", "Poland", "Romania", "Sweden", "Thailand"
    };
    for (size_t i = 0 ; i < 15; i++){
        dat.push_front(countries[i]); 
    }

    // size should be 37 
    if (dat.size() == 37){
        std::cout << "good size: 37" << std::endl; 
    }



    // pop back 8 
    for (size_t i = 0; i < 8; i++){
        dat.pop_back(); 
    }
    // pop front 5 
    for (size_t i = 0; i < 5; i++){
        dat.pop_front(); 
    }

    std::cout << "removed 13 elements, checking size" << std::endl;
    // list should now have : 
    // head->first = 4
    if (dat.size() == 24){
        std::cout << "good size: 24" << std::endl; 
    }
    
    dat.clear(); 
    if (dat.size() != 0){
        std::cout << "size should be 0, but it's " << dat.size() << std::endl; 
    }

    // get val at loc arrsize 
    ULListStr list; 

     std::vector<std::string> movies = {
       "interstellar", "harry potter", "the hunger games", "divergent", 
       "parasite", "tenet", "get out", "the martian", "jaws", "wicked"
        };

    for (size_t i = 0 ; i < 10; i++){
        list.push_back(movies[i]); 
    }

    // now have list of 10 items. remove
    // check push back and push front for when u have to make new list
    list.push_back("the hungover"); 

    if (list.size() != 11){
        std::cout << "size should be 11, but it's " << list.size() << std::endl; 
    }

    list.pop_back(); 


    // test the same for push front 
    list.push_front("the hungover"); 

    if (list.size() != 11){
        std::cout << "size should be 11, but it's " << list.size() << std::endl; 
    }

    list.pop_front(); 

    // list still size 10. 
    // return back element which is wicked
    for (size_t i=0; i < 10; i ++){
        std::cout << i << ": " <<  list.get(i) << std::endl;
    } 
    std::string movie = list.back();
    if (movie != "wicked"){
        std::cout << "movie should be wicked, but it's " << list.back() << std::endl; 
    }

    list.set(9, "wicked 2"); 

    std::cout << "now with wicked 2: " << std::endl;

    for (size_t i=0; i < 10; i ++){
        std::cout << i << ": " <<  list.get(i) << std::endl;
    } 

    list.clear(); 

    if (list.size() != 0){
        std::cout << "cleared list but size isnt 0" << std::endl;
    }

    return 0;
}
