/** 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/15/21
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
}

struct Node* head = NULL;
struct Node* tail = NULL;

void insertHead(int x) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;

	head->next->previous = newNode;
	newNode->next = head->next;
	head->next = newNode;
	newNode->previous = head;
}

void insertTail(int x) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;

	newNode->previous = tail->previous;
	tail->previous->next = newNode;
	newNode->next = tail;
	tail->previous = newNode;
}

void removeHead() {
	struct Node *tempNode = head->next;

	head->next = head->next->next;
	head->next->previous = head;

	free(tempNode);
}

void removeTail() {
	struct Node *tempNode = tail->previous;

	tail->previous = tail->previous->previous;
	tail->previous->next = tail;

	free(tempNode);
}

void printList() {
	struct Node *itr = head;
	while (itr != NULL) {
		printf("%d ", itr->val);
		itr = itr->next;
	}
}

void delete() {
	truct Node *itr = head;
	while (itr != NULL) {
		itr = itr->next;
		free(itr->previous);
	}
	free(tail->previous);
	free(head);
	free(tail)
}