#include <iostream>
#include "Stack.h"

int main() {
    string InputWord;
    cout << "Enter the word: ";
    getline(cin, InputWord);

    Stack<char> Stack(InputWord.size());

    for (int i = 0; i < InputWord.size(); ++i) {
        Stack.push(InputWord[i]);
    }

    cout << Stack.getLength() << endl;

    string ReverseWord;
    while (!Stack.isEmpty()) {
        ReverseWord += Stack.pop();
    }

    cout << "Reverse word: " << ReverseWord << endl;

    return 0;
}
