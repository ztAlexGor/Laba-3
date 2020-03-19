#include <iostream>
#include <cstdlib>
using namespace std;

class List {
private:
	typedef struct node {
		int data;
		node* next;
	}* nodePtr;
	nodePtr head;
	nodePtr temp;
	nodePtr curr;
public:
	List();
	void AddNode(int NewNode);
	void DeleteNode(int DelData);
	void Print();
};