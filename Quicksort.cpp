#include <iostream>
using namespace std;

// Function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int l, int r) {
    // Select the rightmost element as the pivot
    int pivot = arr[r];
    int i = l - 1;

    // Traverse the array and rearrange elements based on the pivot
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            // If the current element is less than the pivot, swap it with the element at index i+1
            i++;
            swap(arr, i, j);
        }
    }

    // Swap the pivot to its correct position
    swap(arr, i + 1, r);

    // Return the index of the pivot element
    return i + 1;
}

// Function to perform QuickSort on the array
void quickSort(int arr[], int l, int r) {
    if (l < r) {
        // Partition the array and get the pivot index
        int pi = partition(arr, l, r);

        // Recursively sort the sub-arrays
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    // Example array
    int arr[5] = {5, 4, 3, 7, 9};

    // Apply QuickSort to the array
    quickSort(arr, 0, 4);

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}