#include "Header.h"

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void List::AddNode(int NewData) {
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

void List::DeleteNode(int DelData) {
	nodePtr delPtr = NULL;
	curr = head;
	temp = head;
	while (curr != NULL && curr->data != DelData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << DelData << " was not in the list\n";
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
	}
}
void List::Print() {
	curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}