/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 1/3/21
 */

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List() {
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous = head;
	count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)

List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List() {
	makeEmpty();
	delete head;
	delete tail;
}

bool List::isEmpty() const { // METHOD COMPLETE
	if (size() == 0) {
		return true;
	} else {
		return false;
	}
}

void List::makeEmpty() { // METHOD COMPLETE
	if (!isEmpty()) {
		ListItr iter(first());
		while (!iter.isPastEnd()) {
			remove(iter.current->value);
			iter.current = first().current;

		}
	}
}

ListItr List::first() { // METHOD COMPLETE
	return head->next;
}

ListItr List::last() { // METHOD COMPLETE
	return tail->previous;
}

void List::insertAfter(int x, ListItr position) { // METHOD COMPLETE
	ListNode* newNode = new ListNode();
	newNode->value = x;

	position.current->next->previous = newNode;
	newNode->next = position.current->next;
	position.current->next = newNode;
	newNode->previous = position.current;
}

void List::insertBefore(int x, ListItr position) { // METHOD COMPLETE
	ListNode* newNode = new ListNode();
	newNode->value = x;

	position.current->previous->next = newNode;
	newNode->previous = position.current->previous;
	position.current->previous = newNode;
	newNode->next = position.current;
}

void List::insertAtTail(int x) { // METHOD COMPLETE
	ListNode* newLast = new ListNode();
	newLast->value = x;

	newLast->previous = tail->previous;
	tail->previous->next = newLast;
	newLast->next = tail;
	tail->previous = newLast;
}

ListItr List::find(int x) { // METHOD COMPLETE
	ListItr iter(head->next);
	while (!iter.isPastEnd()) {
		if (iter.retrieve() == x) {
			return iter;
		} else {
			iter.moveForward();
		}
	}
	return tail;
}

void List::remove(int x) { // METHOD COMPLETE
	ListItr iter = find(x);
	if (!iter.isPastEnd()) {
		iter.current->previous->next = iter.current->next;
		iter.current->next->previous = iter.current->previous;
		delete iter.current;
	}
}

int List::size() const { // METHOD COMPLETE
	int counter = 0;
	ListItr iter(head->next);
	while (!iter.isPastEnd()) {
		iter.moveForward();
		counter++;
	}
	return counter;
}

void printList(List& source, bool forward) { // METHOD COMPLETE
	if (forward == true) {
		ListItr iter(source.first());
		while (!iter.isPastEnd()) {
			cout << iter.retrieve() << " ";
			iter.moveForward();
		}
		cout << "" << endl;

	} if (forward == false) {
		ListItr iter(source.last());
		while (!iter.isPastBeginning()) {
			cout << iter.retrieve() << " ";
			iter.moveBackward();
		}
		cout << "" << endl;
	}
}
