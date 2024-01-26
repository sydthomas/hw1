/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
  Node* head;
  Node(1, head);
  // head->next = Node(2, Node* n);
  // head->next->next = Node(3, Node* w);
  // head->next->next->next = Node(4, Node* h);;
  // head->next->next->next->next = Node(5, Node* q);;

  Node* even = NULL;

  Node* odd = NULL;

// call to recursive function 
  split(head, odd, even);

// check linked listed created 

cout << head->value << endl;
cout << odd->value << endl;
cout << even->value << endl;

}
