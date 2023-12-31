
//correct the code
#include <iostream>

using namespace std;
char dissortedName[] = {'e', 'f', 'a', 'b', 'i', 'r'};
char sorrtedName[] = {'f', 'a', 'r', 'i', 'b', 'a'};

class list {
public:
    char *name;
    char *curr;
    int length;
    int capacity;
    int step;
public:
    void start() {
        curr = name;
    }

    void next() {
        curr++;
    }

    void back() {
        curr--;
    }

    bool nameCheck() {
        bool check = true;
        start();
        for (int i = 0; i < length; ++i) {
            if (*(curr) != dissortedName[i])
                check = false;
        }
        return check;
    }

    void insert(int pos, char value) {
        cout<<"--value--:"<<value<<endl;
        start();
        if (length == capacity) {
            cout << "Full array" << endl;
            return;
        }
        if (pos < 1 && pos > (length + 1)) {
            cout << "Invalid pos" << endl;
            return;
        }
        curr = name + length;
        for (int i = length; i >= pos; i--) {
            *(curr) = *(curr - 1);
            back();
        }
        *(curr) = value;
        length++;
        step++;
    }

    void remove(int pos) {
        if (length == 0) {
            cout << "array is empty" << endl;
            return;
        }
        if (pos < 1 && pos > length) {
            cout << "invalid position" << endl;
            return;
        }
        curr = name + pos - 1;
        for (int i = pos - 1; i < length; ++i) {

            *(curr) = *(curr + 1);
            next();

        }
        length--;
        step++;
    }


    list() {
        length = 6;
        capacity = 6;
        step = 0;
        name = new char[6];
        start();
        for (int i = 0; i < length; ++i) {
            *(curr) = dissortedName[i];
            next();
        }

    }

    ~list() {
        delete[] name;
    }

};


int main() {
    list name;
    while (!name.nameCheck()) {
        name.start();
        for (int i = 0; i < name.length; ++i) {
            cout << *(name.curr);
            name.next();
        }
        cout << endl << "step:" << name.step << endl;
        name.start();
        int option = 0;
        cout << endl << "chose a option:" << endl << "1. Insert." << endl << "2. Remove" << endl, cin >> option;
        switch (option) {
            case 1:
                char value;
                int position;
                cout << "Enter the char value:", cin >> value;
                cout << "Enter the position to insert:", cin >> position;
                name.insert(position, value);
                break;
            case 2:
                int pos;
                cout << "Enter the position to remove: ", cin >> pos;
                name.remove(pos);
                break;
            default:
                cout << "enter a valid option" << endl;
        }

    }
    return 0;
}
