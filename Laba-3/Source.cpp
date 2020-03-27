#include "Header.h"

List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}
List::~List() {

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
    while (curr != NULL && curr->word != DelWord) {
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
    this->size = Size;
    A = new List[this->size];
}
Hash::~Hash() {

}
void Hash::AddElement(string NewWord, string NewMean) {
    int key = HashKey(NewWord);
    A[key].AddNode(NewWord, NewMean);
    score++;
    if (score >= 0.8 * this->size)NewTabl();
}

int Hash::HashKey(string word) {
    int key = 0;
    for (int i = 0; i < word.size(); i++) {
        key += (int)word[i];
    }
    key = key % this->size;
    return key;
}

void Hash::NewTabl() {
    cout << "ALALALALALLALALALAL" << endl;
    this->size *= 2;
    List* B = new List[this->size];
    for (int i = 0; i < this->size/2; i++) {
        while (!(A[i].isEmpty())) {
            List::nodePtr LastElem = A[i].LastElement();
            int key = HashKey(LastElem->word);
            B[key].AddNode(LastElem->word, LastElem->mean);
            A[i].DeleteNode(LastElem->word);
        }
    }
    //delete[] A;
    A = B;
    B = NULL;
}

void Hash::PrintTabl() {
    cout << this->size << endl;
    for (int i = 0; i < this->size; i++) {
        cout << "Ячейка №" << i + 1 << ": ";
        if (A[i].isEmpty())cout << " пуста";
        else A[i].Print();
        cout << endl;
    }
}