#include <iostream>
#include <cstdlib>
using namespace std;

class List {
private:
    typedef struct node {
        string word;
        string mean;
        node* next;
    }*nodePtr;
    nodePtr head;
    nodePtr temp;
    nodePtr curr;
public:
    List();
    void AddNode(string newWord, string NewMean);
    void DeleteNode(string DelWord);
    void Print();
};
class Hash {
private:
	List* A;
	int size;



public:
	Hash(int Size);
    void AddElement(string NewWord, string NewMean);


};