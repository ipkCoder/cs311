
//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

// ====================================================

// HW3P1 llist
// Your name: **
// Complier:  **
// File type: **

//=====================================================

#include <iostream>
using namespace std;

#include "llist.h" 


Node::Node() {}
Node::Node(el_t _elem) : elem(_elem), next(NULL) {}

// Constructor
// - initialize Front and Rear to be NULL and Count = 0.
// - This does not create any node.  The new list is empty.
llist::llist() : front(NULL), rear(NULL), count(0)
{}

// Destructor  
// - while the list is not empty, call deleteFront repeatedly to delete all nodes.
// - Please place a cout in this function "calling the llist desctructor."
llist::~llist() {
	Node* tmp;
	while (front != NULL) {
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

/*
 * Purpose: determine if lihked list is empty
 */
bool llist::isEmpty() {
	return count == 0 ? true : false;
}


/*
 * Purpose: display all elemnts in the linked list
 */
void llist::displayAll() {
		
	cout << "Display: ";
	if (front == NULL) {
		cout << "[ None ]" << endl;
		return;
	}

	Node* tmp = front;
	while (tmp != NULL) {
		cout << "[ " << tmp->elem << " ] ";
		tmp = tmp->next;
	}
	cout << endl;
}

/*
 * Purpose: add element to front of linked list
 * @param el_t NewNum - element to add to linked list
 */
void llist::addFront(el_t NewNum) {
	
	// if no nodes in list, set front and rear pointers to new node
	if (front == NULL) {
		front = new Node(NewNum);
		rear = front;
	} 
	// else, have new node's next pointer point to front element
	// then set front pointer to new node
	else {
		Node* new_node = new Node(NewNum);
		new_node->next = front;
		front = new_node;
	}
	++count;
}

/*
 * Purpose: add element to end of linked list
 * @param el_t NewNum - element to add to linked list
 */
void llist::addRear(el_t NewNum) {
	
	// if list is empty, add to front of list
	if (front == NULL) {
		addFront(NewNum);
	} 
	// else, set rear node's next pointer to point to new node
	// then, update rear pointer to new node
	else {
		rear->next = new Node(NewNum);
		rear = rear->next;
		++count;
	}
}

/*
 * Purpose: delete element from front of linked list
 * @param el_t OldNum - variable to capture element deleted from linked list
 */
void llist::deleteFront(el_t& OldNum) {
	
	// if no elements in linked list, throw Underflow exception since 
	// no elements can be deleted
	if (front == NULL) {
		throw Underflow();
	}
	else {
		OldNum = front->elem;    // store element to be deleted
		Node* tmp = front->next; // set pointer to point to second element, or NULL
		                         // in the case that there is no second element
		delete front;            // delete front element
		front = tmp;             // have front pointer point to second element, or NULL

		if (front == NULL) {     // if, no elements left, set rear to NULL also
			rear = NULL;
		}

		--count; // account for deleted element
	}
}

// - 3 cases
// - error case: if empty, throw an exception.
// - else give back the rear node element through OldNum (pass by reference)
//   and also remove the rear node. Count is updated.
// - (special case: if this is going to make the list empty,
//    make sure both Front and Rear become NULL).
// Regular case:
// OldNum = Rear->Elem;
// Node *p;
// Make p go to the one right before rear (using while)
// delete Rear;
// Rear = p;
void llist::deleteRear(el_t& OldNum) {
	
	if (rear == NULL) { // no nodes
		throw Underflow();
	}

	if (front->next == NULL) { // one node
		deleteFront(OldNum);
	} else { // more than one node
		Node* tmp = front;
		// cout << tmp->elem << " ";
		while (tmp->next != rear) {
			tmp = tmp->next;
			// cout << tmp->elem << " ";
		}
		OldNum = rear->elem;
		delete rear;
		rear = tmp;
		rear->next = NULL;
		--count;
	}
	
// if (front != NULL && rear->next == NULL) {
// 		cout << "count: " << count << " " << rear->elem << endl;
// 		cout << "null" << endl;
// 	}
}

// - 4 cases
// - will delete the Ith node (I starts out at 1).  Count is updated.
// - Error cases: 
//   If I is an illegal value (i.e. > Count or < 1) throw an exception.
// - (note: this may simply call deleteFront or deleteRear for some cases)
void llist::deleteIth(int I, el_t& OldNum) {
	
	if (I < 1 || I > count) {
		throw OutOfRange();
	}
	
	if (I == 1) {
		// cout << "delete Ith: going to delete from front" << endl;
		deleteFront(OldNum);
	} else if (I == count) {
		// cout << "delete Ith: going to delete from rear" << endl;
		deleteRear(OldNum);
	} else {
		// cout << "delete Ith: going to delete from middle" << endl;
		Node* before_ith = front;
		for (int i = 1; i < (I-1); ++i) { // loop through elements until the one before I
			before_ith = before_ith->next;
		}
		Node* ith = before_ith->next;
		OldNum = ith->elem;
		before_ith->next = ith->next;
		delete ith;
		--count;
	}
	
		
	// if (front != NULL && rear->next == NULL) {
	// 	cout << "count: " << count << " " << rear->elem << endl;
	// 	cout << "null" << endl;
	// }
}

// - 4 cases
// -  will add right before the Ith node.  Count is updated.
// -  Error cases:
//    If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.      
// -  (note: this may simply call addFront or addRear for some cases)
void llist::addbeforeIth(int I, el_t NewNum) {

	if (I < 1 || I > count+1) {
		throw OutOfRange();
	}
	// cout << "Count: " << count << endl;
	if (I == 1) {
		addFront(NewNum);
	} else if (I == count+1) {
		// cout << "addbeforeI : " << rear->elem << endl;
		addRear(NewNum);
		// cout << "addbeforeI : " << rear->elem << endl;
	} else {
		// cout << "addbeforeI : " << rear->elem << endl;
		Node* before_ith = front;
		for (int i = 1; i < (I-1); ++i) {
			before_ith = before_ith->next;
		}
		Node* new_node = new Node(NewNum);
		// new_node->elem = NewNum;
		new_node->next = before_ith->next;
		before_ith->next = new_node;
		// cout << "addbeforeI : " << rear->elem << endl;
		++count;
	}
	// cout << "count: " << count << " " << rear->elem << endl;
	// if (rear->next == NULL)
	// 	cout << "null" << endl;
}

void llist::deleteAllFromRear() {
	el_t OldNum;
	while (front != NULL) {	
		deleteRear(OldNum);
		cout << "Deleted " << OldNum << ". " << count << " left" << endl;
	} 
}



