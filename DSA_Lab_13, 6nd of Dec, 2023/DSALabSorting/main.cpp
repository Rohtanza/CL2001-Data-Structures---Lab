#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

void display(std::vector<int> &array) {
    for (const auto i: array)
        std::cout << i << " -> ";
    std::cout << "END" << std::endl;
}

void bubbleSort(std::vector<int> &array) {
    bool swaped;
    size_t OofN(0);
    do {
        swaped = false;
        for (auto i = 0; i < array.size() - 1; ++i)
            if (array.at(i) > array.at(i + 1)) {
                std::swap(array[i], array[i + 1]);
                swaped = true, OofN++;
            }
    } while (swaped);
    display(array);
    std::cout << "O(n) is " << OofN << "." << std::endl;
}


void selectionSort(std::vector<int> &array) {
    size_t OofN(0);
    for (int i = 0; i < array.size() - 1; ++i) {
        int sorted = i; // Treating the first element as the sorted one.
        for (int j = i + 1; j < array.size(); ++j) // We will not check the last index.
            if (array[j] < array[sorted])// finding the min in the array excluded the first element.
                sorted = j;
        if (sorted == i) continue;
        std::swap(array[i], array[sorted]), OofN++;
    }
    display(array);
    std::cout << "O(n) is " << OofN << "." << std::endl;
}

void insertionSort(std::vector<int> &array) {
    size_t size(array.size());
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    display(array);
}

namespace MergerSort {
    void mergeSortedParts(std::vector<int> &array, int l, int m, int r) {
        int leftLength(m - l + 1);
        int rightLength(r - m);

        int temp_left[leftLength];
        int temp_right[rightLength];
        int i, j, k;

        for (int i = 0; i < leftLength; i++)
            temp_left[i] = array[l + i];

        for (int i = 0; i < rightLength; i++)
            temp_right[i] = array[m + 1 + i];

        for (i = 0, j = 0, k = l; k <= r; k++) {

            if ((i < leftLength) && (j >= rightLength || temp_left[i] <= temp_right[j])) {
                array[k] = temp_left[i];
                i++;
            } else {
                array[k] = temp_right[j];
                j++;
            }
        }
    }

    void mergeRecursion(std::vector<int> &array, int l, int r) {

        if (l < r) {
            int m = l + (r - l) / 2;
            mergeRecursion(array, l, m);
            mergeRecursion(array, m + 1, r);

            mergeSortedParts(array, l, m, r);
        }

    }


    void mergeSort(std::vector<int> &array, size_t length) {
        mergeRecursion(array, 0, length);
    }
}

int binarySearchRecursive(std::vector<int> &array, int key, int l, int r, int &comparisons) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    comparisons++;
    if (array[mid] == key) return mid;
    else if (array[mid] > key) return binarySearchRecursive(array, key, l, mid - 1, comparisons);
    else return binarySearchRecursive(array, key, mid + 1, r, comparisons);
}


int binarySearchIterative(std::vector<int> &array, int key) {
    int l = 0;
    int r = array.size() - 1;
    int comparisons = 0;
    while (l <= r) {
        comparisons++;
        int mid = l + (r - l) / 2;
        if (array[mid] == key)
            return mid;
        if (array[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    std::cout << "Comparisons: " << comparisons << std::endl;  // print the number of comparisons
    return -1;
}


int main() {
    size_t arraySize(0);
    int entry;
    std::cout << "Enter Array size: ", std::cin >> arraySize;
    std::vector<int> array(arraySize);
    for (auto i = 0; i < arraySize; ++i) {
        std::cout << "Enter the Element :", std::cin >> entry;
        array[i] = entry;
    }
    display(array);
    while (true) {

        char choice('!');
        std::cout
                << "\nMenu:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Binary Search (Recursive)\n6. Binary Search (Iterative)\n0. Exit\n Enter your choice: ",
                std::cin >> choice;
        switch (choice) {
            case '0':
                return 0;
            case '1':
                bubbleSort(array);
                break;
            case '2':
                selectionSort(array);
                break;
            case '3':
                insertionSort(array);
                break;
            case '4':
                MergerSort::mergeSort(array, array.size() - 1);
                display(array);
                break;
            case '5': {
                int key;
                std::cout << "Enter the value to find: ", std::cin >> key;
                int comparisons = 0;
                std::sort(array.begin(), array.end());
                int result = binarySearchRecursive(array, key, 0, array.size() - 1, comparisons);
                if (result != -1) std::cout << "Element " << key << " found at index :  " << result << std::endl;
                else std::cout << "Element not found\n";
                std::cout << "Comparisons: " << comparisons << std::endl;
                break;
            }
            case '6': {
                int key;
                std::cout << "Enter the value to find: ", std::cin >> key;
                int comparisons = 0;
                std::sort(array.begin(), array.end());
                int result = binarySearchIterative(array, key);
                if (result != -1) std::cout << "Element " << key << " found at index :  " << result << std::endl;
                else std::cout << "Element not found\n";
                break;
            }
            default:
                std::cout << "Invalid choice\n";
        }
    }

}


/*
 * a more optimized code:
 *
#include <iostream>
#include <vector>
#include <algorithm>

void display(const std::vector<int>& array) {
    for (const auto i: array)
        std::cout << i << " -> ";
    std::cout << "END" << std::endl;
}

void bubbleSort(std::vector<int>& array) {
    for (auto i = array.begin(); i != array.end(); ++i)
        for (auto j = array.begin(); j < i; ++j)
            if (*i < *j)
                std::iter_swap(i, j);
    display(array);
}

void selectionSort(std::vector<int>& array) {
    for (auto i = array.begin(); i != array.end(); ++i)
        std::iter_swap(i, std::min_element(i, array.end()));
    display(array);
}

void insertionSort(std::vector<int>& array) {
    for (auto i = array.begin(); i != array.end(); ++i)
        std::rotate(std::upper_bound(array.begin(), i, *i), i, std::next(i));
    display(array);
}

void mergeSort(std::vector<int>& array) {
    std::sort(array.begin(), array.end());
    display(array);
}

int binarySearch(const std::vector<int>& array, int key) {
    auto result = std::lower_bound(array.begin(), array.end(), key);
    if (result != array.end() && *result == key)
        return std::distance(array.begin(), result);
    return -1;
}

int main() {
    std::vector<int> array;
    int entry;
    while (std::cin >> entry)
        array.push_back(entry);
    display(array);
    bubbleSort(array);
    selectionSort(array);
    insertionSort(array);
    mergeSort(array);
    int key;
    std::cout << "Enter the value to find: ", std::cin >> key;
    int result = binarySearch(array, key);
    if (result != -1) std::cout << "Element " << key << " found at index :  " << result << std::endl;
    else std::cout << "Element not found\n";
    return 0;
}

 * */
