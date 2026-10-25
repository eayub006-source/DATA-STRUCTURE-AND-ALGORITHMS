// Data Structures and Algorithms - Lab 03
// Recursion & Searching Algorithms
// Name: Eshal Ayub
// Registration Number: B25F1061AI100

#include <iostream>
using namespace std;

// Task 1: Sum from 1 to n using recursion
int sum(int n)
{
    if (n == 0)
        return 0;

    return n + sum(n - 1);
}

// Task 1: Calculate x raised to power y using recursion
int power(int x, int y)
{
    if (y == 0)
        return 1;

    return x * power(x, y - 1);
}

void task1()
{
    int n, x, y;

    cout << "Enter n: ";
    cin >> n;
    cout << "Sum = " << sum(n) << endl;

    cout << "Enter x and y: ";
    cin >> x >> y;
    cout << x << "^" << y << " = " << power(x, y) << endl;
}

// Task 2: Linear search and count comparisons
int linearSearch(int arr[], int size, int key, int &comparisons)
{
    comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;

        if (arr[i] == key)
            return i + 1;
    }

    return -1;
}

void task2()
{
    int arr[10];
    int key, position, comparisons;

    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    position = linearSearch(arr, 10, key, comparisons);

    if (position == -1)
        cout << "Not found" << endl;
    else
        cout << "Found at position " << position << endl;

    cout << "Comparisons = " << comparisons << endl;
}

// Task 3: Print the first n Fibonacci numbers using recursion
void fibonacci(int n, int first, int second)
{
    if (n == 0)
        return;

    cout << first;

    if (n > 1)
        cout << " ";

    fibonacci(n - 1, second, first + second);
}

void task3()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci sequence: ";
    fibonacci(n, 0, 1);
    cout << endl;
}

// Task 4: Count comparisons in linear and binary search
int linearCount(int arr[], int size, int key)
{
    int comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;

        if (arr[i] == key)
            return comparisons;
    }

    return comparisons;
}

int binaryCount(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;
    int comparisons = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if (arr[mid] == key)
            return comparisons;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return comparisons;
}

void task4()
{
    int arr[1000];

    for (int i = 0; i < 1000; i++)
        arr[i] = i + 1;

    int keys[3] = {1, 50, 100};

    cout << "Key  Linear comparisons  Binary comparisons" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << keys[i] << "        "
             << linearCount(arr, 1000, keys[i]) << "                  "
             << binaryCount(arr, 1000, keys[i]) << endl;
    }
}

// Task 5: Binary search showing low, mid and high at every step
int binarySearch(int arr[], int size, int key, int &steps)
{
    int low = 0;
    int high = size - 1;
    int mid;

    steps = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        steps++;

        cout << "Step " << steps << ": low=" << low
             << " mid=" << mid << " high=" << high;

        if (arr[mid] == key)
        {
            cout << " -> Found at index " << mid << endl;
            return mid;
        }

        cout << endl;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Key not found" << endl;
    return -1;
}

void task5()
{
    int size, key, steps;
    int arr[1000];

    cout << "Enter size of sorted array: ";
    cin >> size;

    cout << "Enter sorted numbers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    binarySearch(arr, size, key, steps);
    cout << "Total steps = " << steps << endl;
}

int main()
{
    // Run one task at a time. Task 1 is active by default.
    task1();

    // task2();
    // task3();
    // task4();
    // task5();

    return 0;
}
