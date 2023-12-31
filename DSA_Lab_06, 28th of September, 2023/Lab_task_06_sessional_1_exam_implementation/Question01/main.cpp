#include <iostream>
#include <array>
#include <algorithm>
/*this using arraylist but a predefined one in the STL in C++*
 * didnt code the whole thing again as it is given in the question
 * that it is already given*/

using namespace std;

void rearrangeList(array<int, 9>& nums, int n) {
    int i = 0, j = 1;
    while (i < n && j < n) {
        while (i < n && nums[i] % 2 != 0) {
            i += 2;
        }
        while (j < n && nums[j] % 2 == 0) {
            j += 2;
        }
        if (i < n && j < n) {
            iter_swap(nums.begin() + i, nums.begin() + j);
            i += 2;
            j += 2;
        }
    }
}

int main() {
    array<int, 9> nums {5, 2, 9, 4, 7, 6, 1, 3, 8};
    int n = nums.size();

    rearrangeList(nums, n);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
