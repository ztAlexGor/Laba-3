#include "Header.h"

List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}
void List::AddNode(string newWord, string NewMean) {
    nodePtr n = new node;
    n->word = newWord;
    n->mean = NewMean;
    n->next = head;
    head = n;
}
void List::DeleteNode(string DelWord) {
    nodePtr delPtr = NULL;
    curr = head;
    temp = head;
    while (curr != NULL && curr->mean != DelWord) {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << DelWord << " was not in the list\n";
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
        cout << curr->word << " " << curr->mean << endl;
        curr = curr->next;
    }
    cout << endl;
}
bool List::isEmpty() {
    if (head == NULL) {
        return 1;
    }
    else return 0;
}
List::nodePtr List::LastElement() {
    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

Hash::Hash(int Size) {
    size = Size;
    A = new List[size];
}

void Hash::AddElement(string NewWord, string NewMean) {
    int key = HashKey(NewWord);
    A[key].AddNode(NewWord, NewMean);
    score++;
}

int Hash::HashKey(string word) {
    int key = 0;
    for (int i = 0; i < word.size(); i++) {
        key += (int)word[i];
    }
    key = key % size;
    return key;
}

void Hash::NewTabl() {
    size *= 2;

    List* B = new List[size];

    for (int i = 0; i < size / 2; i++) {

    }
}

void Hash::PrintTabl() {
    for (int i = 0; i < size; i++) {
        cout << "Ячейка №" << i + 1 << ": ";
        A[i].Print();
        cout << endl;
    }
}