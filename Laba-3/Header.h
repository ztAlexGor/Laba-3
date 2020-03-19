#include <iostream>
#include <cstdlib>
using namespace std;

class Link {
private:
	typedef struct node {
		int data;
		node* next;
	}* nodePtr;
public:
	Link();
	void AddNode(int NewNode);
	void DeleteNode(int DelData);
	void Print();
};