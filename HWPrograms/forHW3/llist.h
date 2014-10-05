
//****************************************************************************
//  CS311 Linked - by Rika for those who could not get HW3 to work
//  Header File  llist.h
//****************************************************************************

#ifndef llist_H
#define llist_H

typedef int el_t ;

	   // list node is defined here as a struct Node
struct Node {
  el_t elem;   // elem is the element stored
  Node* next;  // next is the pointer to the next node
  Node();
  Node(el_t _elem);
};

// I could have done class Node and add the data members under public
// but it will use too much space

class llist {

protected:

    Node* front;       // front  pointer 
    Node* rear;        // rear   pointer
    int   count;        // counter for the number of elements

public:

    class Underflow{};
    class OutOfRange {};
      
    llist ();                       // constructor  
    ~llist();                       // destructor

    bool isEmpty();
      
    void displayAll();
      
    void addFront(el_t NewNum);

    void addRear(el_t NewNum);
      
    void addbeforeIth(int I, el_t newNum);

    void deleteFront(el_t& OldNum);
      
    void deleteRear(el_t& OldNum);
      
    void deleteIth(int I, el_t& OldNum);

    void deleteAllFromRear();
    
};

#endif
