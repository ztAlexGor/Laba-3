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

Hash::Hash(int Size, string Word) {
    size = Size;
    A = new List[size];
<<<<<<< HEAD
}
void List::AddElement(string NewWord, string NewMean) {
    int key = HashKey(NewWord);
    A[key].AddNode(NewWord, NewMean);
=======
    word = Word;
}

Hash::HashKey() {
    int key = 0;
    for (int i = 0; i < word.size(); i++) {
        key += (int)word[i];
    }
    key /= size;
    return key;
>>>>>>> 8c42513df8bf9a9f1083a58769d72b2bd9f11387
}