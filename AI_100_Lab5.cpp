#include <iostream>
using namespace std;

// Task 1: Bubble Sort with user input (maximum 10 elements)
void task1() {
    int arr[10], n;

    cout << "Enter number of elements (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid size. Please enter a number from 1 to 10.\n";
        return;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << '\n';
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Task 2: Selection Sort in descending order; reports largest position each pass
void task2() {
    int arr[10] = {10, 34, 45, 33, 23, 47, 31, 23, 45, 69};
    int n = 10;

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Report the position in the unsorted array before swapping (1-based).
        cout << "Pass " << i + 1 << ": largest value = " << arr[maxIndex]
             << ", position = " << maxIndex + 1 << '\n';

        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    cout << "Sorted array (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Task 3: Insertion Sort with a count of element shifts
void task3() {
    int arr[10] = {12, 31, 41, 37, 49, 45, 69, 2, 56, 76};
    int n = 10;
    int shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            shifts++; // Count each element moved one position to the right.
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal shifts: " << shifts << '\n';
}

// Task 4: Optimized Bubble Sort; stops after a pass with no swaps
void task4() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int passes = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        passes++;
        if (!swapped) {
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nPasses needed: " << passes << '\n';
}

// Task 5: Compare comparison counts for all three sorting algorithms
void task5() {
    const int n = 10;
    int original[n] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int bubble[n], selection[n], insertion[n];

    for (int i = 0; i < n; i++) {
        bubble[i] = original[i];
        selection[i] = original[i];
        insertion[i] = original[i];
    }

    long long bubbleComparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            bubbleComparisons++; // Count each adjacent-element comparison.
            if (bubble[j] > bubble[j + 1]) {
                int temp = bubble[j];
                bubble[j] = bubble[j + 1];
                bubble[j + 1] = temp;
            }
        }
    }

    long long selectionComparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            selectionComparisons++; // Count each comparison used to find the minimum.
            if (selection[j] < selection[minIndex]) {
                minIndex = j;
            }
        }
        int temp = selection[i];
        selection[i] = selection[minIndex];
        selection[minIndex] = temp;
    }

    long long insertionComparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = insertion[i];
        int j = i - 1;

        // Count only comparisons between array elements, not the j >= 0 boundary test.
        while (j >= 0) {
            insertionComparisons++;
            if (insertion[j] > key) {
                insertion[j + 1] = insertion[j];
                j--;
            } else {
                break;
            }
        }
        insertion[j + 1] = key;
    }

    cout << "Algorithm comparison counts:\n";
    cout << "Bubble Sort: " << bubbleComparisons << '\n';
    cout << "Selection Sort: " << selectionComparisons << '\n';
    cout << "Insertion Sort: " << insertionComparisons << '\n';
    cout << "Least element comparisons: Insertion Sort\n";
    cout << "Insertion Sort makes fewer element comparisons for this input because "
         << "it stops scanning the sorted portion when the correct position is found.\n";
}

int main() {
    // Run one task at a time. Task 1 is active by default.
    task1();

    // Uncomment exactly one of the following calls to run another task:
    // task2();
    // task3();
    // task4();
    // task5();

    return 0;
}
