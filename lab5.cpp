#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string textInput;

    char codeLine[] = "this is code line";
    char codeSymbols[26];
    const char Alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
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
    int lenght = textInput.length();
    for(int i = 0; i < lenght; i++)
    textInput[i] = tolower(textInput[i]);
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
