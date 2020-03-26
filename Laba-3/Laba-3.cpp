#include "Header.h"
void ReadFile(Hash k);

int main()
{
    setlocale(LC_ALL, "rus");
    Hash Slovarik(2);
    ReadFile(Slovarik);
    Slovarik.PrintTabl();
}

void ReadFile(Hash k) {
    ifstream cach;
    string word, mean;
    cach.open("test.txt");
    while (!cach.eof()) {
        int i = 0;
        getline(cach, mean);
        while (mean[i] != ';') {
            word += mean[i];
            i++;
        }
        mean.erase(0, i);
        k.AddElement(word, mean);
        word.clear();
        mean.clear();
        i = 0;
    }
}