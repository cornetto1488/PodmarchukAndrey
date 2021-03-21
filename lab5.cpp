#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string textInput;

    char codeLine[] = "this is code line";
    char codeSymbols[26];
    const char Alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i',' j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
        'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int position = 0;

    for (int i = 0; i < strlen(codeLine); i++) {
        if ((codeLine[i] < 122) && (codeLine[i] > 97)) {
            bool trigger = false;
            for (int j = 0; j < 26; j++) {
                if (codeLine[i] == codeSymbols[j]) {
                    trigger = true;
                    break;
                }
            }
            if (!trigger) {
                codeSymbols[position] = codeLine[i];
                position++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        bool trigger = false;
        for (int j = 0; j < 26; j++) {
            if (Alphabet[i] == codeSymbols[j]) {
                trigger = true;
                break;
            }
        }
        if (!trigger) {
            codeSymbols[position] = Alphabet[i];
            position++;
        }
    }
    cout << "This is code line: " << codeLine << endl;
    cout << "This is codeSymbols:" << endl;
    for (int i = 0; i < 26; i++) {
        cout.width(2);
        cout << codeSymbols[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 26; i++) {
        cout.width(2);
        cout << i + 1 << " ";
    }
    cout << endl;

    cout << "Enter text to encoder: ";

    getline(cin, textInput);
    transform(textInput.begin(), textInput.end(), textInput.begin(), tolower);
    int lenght = textInput.length();
    const char* textC = textInput.c_str();

    for (int i = 0; i < lenght; i++) {
        bool trigger = false;
        for (int j = 0; j < 26; j++) {
            if (textC[i] == codeSymbols[j])
            {
                trigger = true;
                cout << j + 1 << " ";
                break;
            }
        }
        if (!trigger) {
            cout << "00 ";
        }
    }
    return 0;
}