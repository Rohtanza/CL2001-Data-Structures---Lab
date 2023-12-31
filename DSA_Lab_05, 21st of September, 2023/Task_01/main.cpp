#include <iostream>
#include "Stack.h"
#include <memory>

using namespace std;

int main() {
    int NumberOne(0), NumberTwo(0);
    cout << "Enter number one value : ", cin >> NumberOne;
    cout << "Enter number two value : ", cin >> NumberTwo;


    cout << "Number One : " << NumberOne << "\nNumber two : " << NumberTwo << endl;

    Stack<int> list;

    list.push(NumberOne);
    list.push(NumberTwo);

    NumberOne = list.pop();
    NumberTwo = list.pop();

    cout << "Number One : " << NumberOne << "\nNumber two : " << NumberTwo << endl;


    return 0;
}
