/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/


//#include <gtest/gtest.h>

#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <map>

#include "split.h"

int main(int argc, char* argv[])
{
    std::vector<int> nums = {
        3, 7, 12, 18, 21, 25, 29, 33, 36, 40,
        45, 48, 52, 56, 60, 62, 66, 70, 73, 75,
        77, 81, 84, 89, 90, 91, 95, 98, 100, 104,
        109, 113, 118, 123, 127, 131, 136, 140, 144, 149,
        153, 158, 162, 167, 171, 176, 181, 185, 190, 195
      };
    

// altered from provided test case to us from the csci104 files 
      // create head
		Node* head = new Node(nums[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(nums.cbegin());
		++nextValIter;

		for(; nextValIter != nums.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}

// made list. 

// list: 
std::cout << "making list!! " << std::endl;
Node* temp = head; 
for(size_t i = 0; i < 50 ; i++){
    std::cout << temp->value << ", "; 
    if (i % 11 == 0){
        std:: cout << std::endl; 
    } 
    temp = temp->next; 
}



Node* odds = nullptr;
Node* evens = nullptr; 

split(head, evens, odds); 
std::cout << "odds list:   " << std::endl;

temp = evens; 
int i = 0; 
while (temp != NULL){
    std::cout << temp->value << ", "; 
    if (i % 11 == 0){
        std:: cout << std::endl; 
    } 
    i++; 
    temp = temp->next; 
}

std::cout << "odds list:   " << std::endl;


temp = odds;
i=0;  
while(temp != NULL){
    std::cout << temp->value << ", "; 
    if (i % 11 == 0){
        std:: cout << std::endl; 
    } 
    i++; 
    temp = temp->next; 
}

// now cout what i got 



}
