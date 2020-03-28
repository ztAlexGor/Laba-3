#include "Header.h"
void ReadFile(Hash* k);
void Link();

int main()
{
    setlocale(LC_ALL, "rus");
    Hash Slovarik(3);
    ReadFile(&Slovarik);
    return 0;
}

void ReadFile(Hash* k) {
    ifstream cach;
    string word, mean;
    cach.open("C:\\Users\\lexa3\\OneDrive\\Рабочий стол\\git-playground-master\\nice-project\\Laba-3\\Laba-3\\test.txt");
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
    (*k).PrintTabl();
    cach.close();
}

void Link() {
    cout << "Enter sentence to get definition of words:" << endl;
    
    string sentence, word;

    cin >> sentence;
    
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != ':' && sentence[i] != '.') {
            if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122)
                sentence[i] = (char)((int)sentence[i] - 32);
            word += sentence[i];
        }
        else
            if (!word.empty()) {
                /////////////////////////////////////////
                /////////////////////////////////////////
                /////////////////////////////////////////

            }
    }
}