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


#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

/*
- need to add value to apporitate new list 
    - if its the 1st value make that be pointed by the header ptr 
- in (og list) needs to just have a value of null 
- call function recuersively with differnet imputs (->next) usign next
*/
  Node* curr = in;
  
  if(in != nullptr){
    in = curr->next;

    if(curr->value % 2 == 0){
      curr->next = evens;
      evens = curr;
    }
    else{ //if(in->value % 1 == 0){
      //odd
      curr->next = odds;
      odds = curr; 

    }
    split(in, odds, evens);
  }
  else{
    in = nullptr;
    //evens = nullptr;
    //odds = nullptr;
    //return;
  }

}

/* If you needed a helper function, write it here */

