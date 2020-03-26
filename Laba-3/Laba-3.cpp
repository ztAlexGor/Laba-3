#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Hash Slovarik(2);
    string word, mean;
    cin >> word;
    cin >> mean;
    Slovarik.AddElement(word, mean);
    Slovarik.PrintTabl();
}