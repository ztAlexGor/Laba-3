#include "Header.h"
void ReadFile(Hash *k);
void Link(Hash *k);

int main()
{
    setlocale(LC_ALL, "rus");
    Hash Slovarik(32000);
    ReadFile(&Slovarik);
    //Slovarik.PrintTabl();
    Link(&Slovarik);
    return 0;
}

void ReadFile(Hash* k) {
    ifstream cach;
    string word, mean;
    cach.open("D:\\Учёба\\Файлы общего доступа\\boom.txt");
    while (!cach.eof()) {
        int i = 0;
        getline(cach, mean);
        while (mean[i] != ';') {
            word += mean[i];
            i++;
        }
        mean.erase(0, i + 1);
        (*k).AddElement(word, mean);
        word.clear();
        mean.clear();
        i = 0;
    }
    cach.close();
}

void Link(Hash *k) {
    bool z = true;
    char q;
    while (z) {
        cout << "Enter sentence to get definition of words:" << endl;
        string sentence, word;

        getline(cin, sentence);
        sentence += '.';
        cout << endl;

        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != ':' && sentence[i] != '.') {
                if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122)
                    sentence[i] = (char)((int)sentence[i] - 32);
                word += sentence[i];
            }
            else
                if (!word.empty()) {
                    (*k).Search(word);
                    word.clear();
                    cout << endl;
                }
        }
        cout << "Enter \"0\" to exit." << endl << "Enter \"1\" to enter one more sentence.";
        q = _getch();
        system("cls");
        if (q == '0')
            z = false;
    }
}