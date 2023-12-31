#include <iostream>
#include <ctime>
#include <algorithm>
#include <bits/stdc++.h>


#define Row 4
#define Col 7
using namespace std;

int main() {

    srand(time(NULL));
    double monthlyTemps[Row][Col];
    for (auto &row: monthlyTemps) {
        for (auto &col: row) {
            col = rand() % 21 + 10;
        }
    }
    for (auto &row: monthlyTemps) {
        for (auto &col: row) {
            cout << col << '\370' << "C" << "   ";
        }
        cout << endl;
    }
    for (int i = 0; i < Row; ++i) {
        cout << "Hottest Day of Week No " << i+1 << ": " << *max_element(monthlyTemps[i], monthlyTemps[i] + Col) << endl;
    }

    return EXIT_SUCCESS;
}
