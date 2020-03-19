#include "Header.h"

Link::Link() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void Link::AddNode(int NewData) {
	nodePtr n = new node;
	n->data = NewData;
	n->next = NULL;
	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
}