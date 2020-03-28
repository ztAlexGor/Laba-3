#include "Header.h"

List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}
List::~List() {
    while (head != NULL) {
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        DeleteNode(curr->word);
    }
    temp = NULL;
    curr = NULL;
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
        cout << endl;
    }
    
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
void List::Search(string Word) {
    curr = head;
    while (curr->word != Word && curr != NULL) {
        curr = curr->next;
    }
    if (curr == NULL)cout << "Word " << Word << " not in this list" << endl;
    else cout << curr->mean << endl;
}

Hash::Hash(int Size) {
    this->size = Size;
    A = new List[this->size];
}
Hash::~Hash() {
    delete[] A;
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
    delete[] A;
    A = B;
    B = NULL;
}

void Hash::PrintTabl() {
    for (int i = 0; i < this->size; i++) {
        if (A[i].isEmpty())cout << "Ячейка №" << i + 1 << ": пуста\n"<<endl;
        else {
            cout << "Ячейка №" << i + 1 << ":" << endl;
            A[i].Print();
        }
        cout << endl;
    }
}

void Hash::Search(string Word) {
    int Search_key = HashKey(Word);
    A[Search_key].Search(Word);
}