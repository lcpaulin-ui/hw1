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
    dat.push_back("hi");
    dat.push_back("bye");
    //std::cout << "hi " << std::endl;
    std::cout << dat.get(0) << std::endl;

    return 0;
}
