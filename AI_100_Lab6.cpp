#include <iostream>
using namespace std;

int comparisons = 0;
int arraySize = 0;
bool showSteps = false;

// Print the complete array.
void printArray(int arr[])
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ------------------------------------------------
// QUICK SORT USING HOARE PARTITION
// This follows the Hoare example from the lab notes.
// ------------------------------------------------

int partitionHoare(int arr[], int low, int high)
{
    int pivot = arr[low];       // First element is the pivot.

    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        // Move i from left to right.
        do
        {
            i++;
            comparisons++;
        }
        while (arr[i] < pivot);

        // Move j from right to left.
        do
        {
            j--;
            comparisons++;
        }
        while (arr[j] > pivot);

        // Stop when the two positions meet or cross.
        if (i >= j)
        {
            if (showSteps == true)
            {
                cout << "Array after partition: ";
                printArray(arr);
            }

            return j;
        }

        // Swap the two numbers using a temporary variable.
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortHoare(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionHoare(arr, low, high);

        // Sort the left part.
        quickSortHoare(arr, low, p);

        // Sort the right part.
        quickSortHoare(arr, p + 1, high);
    }
}

// ------------------------------------------------
// QUICK SORT USING LOMUTO PARTITION
// This follows the simple temp-variable style
// from the Lomuto example in the lab notes.
// ------------------------------------------------

int partitionLomuto(int arr[], int low, int high)
{
    int pivot = arr[high];       // Last element is the pivot.
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        comparisons++;

        if (arr[j] <= pivot)
        {
            i++;

            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Put the pivot in its correct position.
    int temp;
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    if (showSteps == true)
    {
        cout << "Pivot " << pivot << " is at index " << i + 1 << endl;
        cout << "Array: ";
        printArray(arr);
    }

    return i + 1;
}

void quickSortLomuto(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionLomuto(arr, low, high);

        // Sort the left part.
        quickSortLomuto(arr, low, p - 1);

        // Sort the right part.
        quickSortLomuto(arr, p + 1, high);
    }
}

// ------------------------------------------------
// MERGE SORT
// ------------------------------------------------

void merge(int arr[], int temp[], int left, int middle, int right)
{
    if (showSteps == true)
    {
        cout << "Merging left part (index " << left << " to " << middle << "): ";
        for (int i = left; i <= middle; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Merging right part (index " << middle + 1 << " to " << right << "): ";
        for (int i = middle + 1; i <= right; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int i = left;
    int j = middle + 1;
    int k = left;

    // Compare numbers from the two parts.
    while (i <= middle && j <= right)
    {
        comparisons++;

        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy the remaining numbers from the left part.
    while (i <= middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining numbers from the right part.
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted numbers back to the original array.
    for (int x = left; x <= right; x++)
    {
        arr[x] = temp[x];
    }

    if (showSteps == true)
    {
        cout << "After merging: ";
        for (int x = left; x <= right; x++)
        {
            cout << arr[x] << " ";
        }
        cout << endl << endl;
    }
}

void mergeSortAgain(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        mergeSortAgain(arr, temp, left, middle);
        mergeSortAgain(arr, temp, middle + 1, right);

        merge(arr, temp, left, middle, right);
    }
}

void mergeSort(int arr[], int size)
{
    int temp[20];     // The lab arrays have fewer than 20 numbers.

    mergeSortAgain(arr, temp, 0, size - 1);
}

// ------------------------------------------------
// TASK 1: HOARE QUICK SORT
// ------------------------------------------------

void task1()
{
    int arr[16] = {10, 34, 45, 33, 23, 47, 31, 23,
                   45, 69, 2, 56, 7, 67, 88, 42};

    arraySize = 16;
    showSteps = true;
    comparisons = 0;

    cout << "TASK 1 - QUICK SORT USING HOARE" << endl;
    cout << "Original array: ";
    printArray(arr);

    quickSortHoare(arr, 0, arraySize - 1);

    cout << "Sorted array: ";
    printArray(arr);

    showSteps = false;
}

// ------------------------------------------------
// TASK 2: LOMUTO QUICK SORT
// ------------------------------------------------

void task2()
{
    int arr[16] = {10, 34, 45, 33, 23, 47, 31, 23,
                   45, 69, 2, 56, 7, 67, 88, 42};

    arraySize = 16;
    showSteps = true;
    comparisons = 0;

    cout << "TASK 2 - QUICK SORT USING LOMUTO" << endl;
    cout << "Original array: ";
    printArray(arr);

    quickSortLomuto(arr, 0, arraySize - 1);

    cout << "Sorted array: ";
    printArray(arr);

    showSteps = false;
}

// ------------------------------------------------
// TASK 3: MERGE SORT
// ------------------------------------------------

void task3()
{
    int arr[14] = {10, 34, 33, 22, 77, 98, 2,
                   56, 7, 55, 56, 67, 88, 42};

    int size = 14;
    arraySize = size;
    showSteps = true;
    comparisons = 0;

    cout << "TASK 3 - MERGE SORT" << endl;
    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr);

    showSteps = false;
}

// ------------------------------------------------
// TASK 4: COMPARISON COUNTS
// ------------------------------------------------

void task4()
{
    int randomArray[10] = {6, 2, 9, 4, 1, 8, 3, 10, 5, 7};
    int sortedArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reverseArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int arr1[10], arr2[10], arr3[10];
    int h, l, m;

    arraySize = 10;
    showSteps = false;

    cout << "TASK 4 - COMPARISON COUNTS" << endl;
    cout << "Input             Hoare    Lomuto    Merge" << endl;

    // RANDOM ARRAY
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = randomArray[i];
        arr2[i] = randomArray[i];
        arr3[i] = randomArray[i];
    }

    comparisons = 0;
    quickSortHoare(arr1, 0, 9);
    h = comparisons;

    comparisons = 0;
    quickSortLomuto(arr2, 0, 9);
    l = comparisons;

    comparisons = 0;
    mergeSort(arr3, 10);
    m = comparisons;

    cout << "Random            " << h << "        " << l << "        " << m << endl;

    // ALREADY SORTED ARRAY
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = sortedArray[i];
        arr2[i] = sortedArray[i];
        arr3[i] = sortedArray[i];
    }

    comparisons = 0;
    quickSortHoare(arr1, 0, 9);
    h = comparisons;

    comparisons = 0;
    quickSortLomuto(arr2, 0, 9);
    l = comparisons;

    comparisons = 0;
    mergeSort(arr3, 10);
    m = comparisons;

    cout << "Already sorted    " << h << "        " << l << "        " << m << endl;

    // REVERSE SORTED ARRAY
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = reverseArray[i];
        arr2[i] = reverseArray[i];
        arr3[i] = reverseArray[i];
    }

    comparisons = 0;
    quickSortHoare(arr1, 0, 9);
    h = comparisons;

    comparisons = 0;
    quickSortLomuto(arr2, 0, 9);
    l = comparisons;

    comparisons = 0;
    mergeSort(arr3, 10);
    m = comparisons;

    cout << "Reverse sorted    " << h << "        " << l << "        " << m << endl;
}

// ------------------------------------------------
// TASK 5: WRITTEN TASK
// ------------------------------------------------

void task5()
{
    cout << "Task 5 must be completed on paper." << endl;
    cout << "Draw the first partition of Hoare and Lomuto." << endl;
    cout << "Also draw the Merge Sort divide-and-merge diagram." << endl;
}

// ------------------------------------------------
// OPTIONAL: SORT IN DESCENDING ORDER
// ------------------------------------------------

int partitionDescending(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        }
        while (arr[i] > pivot);

        do
        {
            j--;
        }
        while (arr[j] < pivot);

        if (i >= j)
        {
            return j;
        }

        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortDescending(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionDescending(arr, low, high);
        quickSortDescending(arr, low, p);
        quickSortDescending(arr, p + 1, high);
    }
}

void optionalChallenge()
{
    int arr[5] = {8, 3, 5, 1, 9};

    arraySize = 5;
    quickSortDescending(arr, 0, arraySize - 1);

    cout << "Descending order: ";
    printArray(arr);
}

// ------------------------------------------------
// MAIN FUNCTION
// Only Task 1 is active.
// Comment it and uncomment another task to run it.
// ------------------------------------------------

int main()
{
    task1();

    // task2();
    // task3();
    // task4();
    // task5();
    // optionalChallenge();

    return 0;
}
