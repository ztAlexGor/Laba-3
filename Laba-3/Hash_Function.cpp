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