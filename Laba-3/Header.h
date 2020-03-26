#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct node;

class List {
private:
    friend class Hash;
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
    bool isEmpty();
    node* LastElement();
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
    void AddElement(string NewWord, string NewMean);
    void PrintTabl();

};