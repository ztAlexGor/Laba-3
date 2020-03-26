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
<<<<<<< HEAD


=======
    int score;
    int HashKey(string word);
    void NewTabl();
>>>>>>> 334f81f60fda39f8f7dad217d4694d4bbe2f0bbb

public:
	Hash(int Size);
    void AddElement(string NewWord, string NewMean);


};