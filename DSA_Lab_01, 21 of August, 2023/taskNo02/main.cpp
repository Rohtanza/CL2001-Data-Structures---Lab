#include <iostream>
#include <limits>

using namespace std;

void operations();

void pendNdFreq(string &input);

bool isPend(string &input);

void Freq(string &input);

int main() {
    operations();
    return 0;
}

void operations() {
    string inputString;
    while (true) {
        auto option = 0;
        cout << "\t*Enter 1 for Input \n\t*Enter 2 to Exit\n\t=>", cin >> option;
        switch (option) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter String : ", getline(cin, inputString);
                system("CLS");
                pendNdFreq(inputString);
                break;
            case 2:
                exit(0);
            default:
                system("CLS");
                cout << "Enter a Valid Value" << endl;
                operations();
                break;
        }
    }
}

void pendNdFreq(string &input) {

    if (isPend(input))
        cout << "yes its palindrome" << endl;
    else
        cout << "No it ain't palindrome" << endl;

    Freq(input);

}

bool isPend(string &input) {
    size_t stringSize = input.size();
    const char *start = &input[0];
    const char *end = &input[stringSize - 1];

    for (size_t i = 0; i < stringSize / 2; ++i) {
        if (*start != *end)
            return false;
        start++;
        end--;
    }
    return true;
}

void Freq(string &input) {

    char freqElement;
    cout << "Enter the char to check the frequency : ", cin >> freqElement;
    size_t count = 0;
    for (char element : input) {
        if (freqElement == element)
            count++;
    }
    std::cout << "The Frequency is: " << count << std::endl;
}