#include <iostream>
#include <cstdlib>
using namespace std;

class List {
private:
    typedef struct node {
        string word;
        string data;
        node* next;
    }*nodePtr;
    nodePtr head;
    nodePtr temp;
    nodePtr curr;
public:
    List();
    void AddNode(string newWord, string NewData);
    void DeleteNode(string DelData);
    void Print();
};

class Hash {
private:
	List* A;
	int size;
    int score;
    int HashKey(string word);
    void NewTabl();

public:
	Hash(int Size);



};