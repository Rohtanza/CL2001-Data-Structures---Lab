#include <iostream>
using namespace std;

void swapNumbers(int *one, int *two);

int main() {
    int one, two;
    cout << "Enter the first number: ";
    cin >> one;
    cout << "Enter the second number: ";
    cin >> two;
    swapNumbers(&one, &two);
    cout << "Now the first number is " << one << " and the second number is " << two << endl;
    return 0;
}

void swapNumbers(int *one, int *two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}
