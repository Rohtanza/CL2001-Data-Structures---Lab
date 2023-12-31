#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[]) {
    int comparisons = 0;
   // implement the bubble sort logic here
   	// display the array after each pass (inner loop)
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[]) {
    int comparisons = 0;
    // implement the selection sort logic here
    	// display the array after each pass (inner loop)
    cout << "Selection Sort Comparisons: " << comparisons << endl;
    
}

void insertionSort(int size, int arr[])
{
	int comparisons = 0;
    // implement the insertion sort logic here
    	// display the array after each pass (inner loop)
    cout << "Insertion Sort Comparisons: " << comparisons << endl;
}

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right) {

}


void mergeSort(int arr[], int l, int r) {
  
}


int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons) {
    // implement the recursive binary search logic here
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons) {
   // implement the iterative binary search logic here
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display the menu
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Binary Search (Recursive)\n";
    cout << "6. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(size, arr);
            break;
        case 2:
            selectionSort(size, arr);
            break;
        case 3:
            insertionSort(size, arr);
            display(size, arr);
            break;
        case 4:
            mergeSort(arr, 0, size-1);
            display(size, arr);
            break;
        case 5: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        case 6: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchIterative(arr, size, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
