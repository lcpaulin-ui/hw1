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
void addNode(Node*& head, Node*& add); 

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
  // WRITE YOUR CODE HERE

  // empty case 
  if(in == 0){
    return;
  }

  // evens 
  else if ( ( in->value ) % 2 == 0 ){
    addNode(evens, in); 
  }

  // odds 
  else {
    addNode(odds, in);
  }

}

/* If you needed a helper function, write it here */
// helper function to traverse the list to the end, to add the new node.

// pass in head pointer, use it to traverse to list's end and point to inserted node

void addNode(Node*& head, Node*& add){
  Node* temp = head; 
  // if list empty, make added node the head 
  if(head == nullptr){
    head = add;
    return;
  }
  else if (temp->next == nullptr){
    temp->next = add;
    return;  
  }
  else
  {
    return addNode(temp->next, add); 
  }
 }
