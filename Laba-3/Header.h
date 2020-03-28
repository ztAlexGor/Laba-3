#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

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
    nodePtr LastElement();
    void Search(string Word);
    void Print();
    ~List();
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
    ~Hash();
    void AddElement(string NewWord, string NewMean);
    void PrintTabl();
    void Search(string Word);
};