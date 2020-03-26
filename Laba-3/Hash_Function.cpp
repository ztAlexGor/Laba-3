#include "Header.h"

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
    Hash NewHashTable;
    for (int i = 0; i < size; i++) {
        while (!(A[i].isEmpty)) {
            List::nodePtr LastElem = A[i].LastElement();
            NewHashTable.AddElement(LastElem->word, LastElem->mean);
            A[i].DeleteNode(LastElem->word);
        }
    }
    this = NewHashTable;
}

void Hash::PrintTabl() {
    for (int i = 0; i < size; i++) {
        cout << "Ячейка №" << i + 1 << ": ";
        A[i].Print();
        cout << endl;
    }
}