/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
/*
struct Node 
{
  int value;
  Node* next;
}
*/


#include "split.h"

/* Add a prototype for a helper function here if you need */
//void addNode(Node*& in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
  // WRITE YOUR CODE HERE

  // empty case 
  if(in == nullptr){
    return;
  }

  else if (in->value % 2 == 0){

    if(evens == nullptr) {
      evens = in;
      evens->next = nullptr; 
    }
    else {
      Node* temp = evens;
      evens = in;
      evens->next = temp; 
    }
  
  }

  else {
    if (odds == nullptr){
      odds = in;
      odds->next = nullptr;
    }

    else{
      Node* temp = odds;
      odds = in;
      odds->next = temp;
    }
  }

  in = in->next; 

  return split(in, odds, evens); 


}

/* If you needed a helper function, write it here */
// helper function to traverse the list to the end, to add the new node.

// pass in head pointer, use it to traverse to list's end and point to inserted node
/**
void addNode(Node*& head, Node*& odds, Node*& evens){
  Node* temp = head; 
  // get a pointer to next node 
  Node* newHead = head; 

  else if (head->value % 2 == 0){
    
  }
 }
*/