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
void addNode(Node*& in, Node*& list);

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
  // WRITE YOUR CODE HERE 

  // empty case
  if (in == nullptr){
    return;
  }

  // take my ptr out of og list aka move head ptr to next pointer 
  Node* curr = in;
  in = in->next; 

  if (curr->value % 2 == 0){
    addNode(curr, evens);
  }
  else {
    addNode(curr, odds);
  }

  return split(in, odds, evens);

}

/* If you needed a helper function, write it here */
// helper function to traverse the list to the end, to add the new node.

// pass in head pointer, use it to traverse to list's end and point to inserted node

void addNode(Node*& add, Node*& list){ 

  // empty list case 
  if (list == nullptr){
    list = add;
    list->next = nullptr; 
  }

  // got to the end case 
  else if (list->next == nullptr){
    list->next = add;
    add->next = nullptr;
    return; 
  }

  else {
    addNode(add, list->next);
  }

}