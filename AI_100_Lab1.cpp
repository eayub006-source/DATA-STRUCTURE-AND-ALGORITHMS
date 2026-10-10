#include <iostream>
using namespace std;

// ==================================================
// Task 1: Determine grades of 10 students
// ==================================================
void task1() {
    int marks[10] = {
        80, 72, 93, 87, 90,
        55, 66, 74, 69, 56
    };

    for (int i = 0; i < 10; i++) {
        cout << "Student " << i + 1
             << ": Marks = " << marks[i]
             << ", Grade = ";

        if (marks[i] >= 90)
            cout << "A";
        else if (marks[i] >= 82)
            cout << "B+";
        else if (marks[i] >= 72)
            cout << "B";
        else if (marks[i] >= 66)
            cout << "C";
        else if (marks[i] >= 60)
            cout << "D";
        else
            cout << "F";

        cout << endl;
    }
}

// ==================================================
// Task 2: Find maximum and minimum using functions
// ==================================================
float max(float a, float b) {
    return (a > b) ? a : b;
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

void task2() {
    float numbers[5];

    cout << "Enter 5 numbers: ";

    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    float maximum = numbers[0];
    float minimum = numbers[0];

    for (int i = 1; i < 5; i++) {
        maximum = max(maximum, numbers[i]);
        minimum = min(minimum, numbers[i]);
    }

    cout << "Maximum = " << maximum << endl;
    cout << "Minimum = " << minimum << endl;
}

// ==================================================
// Task 3: Print a histogram using stars
// ==================================================
void task3() {
    int numbers[10];

    cout << "Please enter 10 numbers:" << endl;

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    cout << "Element\tValue\tHistogram" << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << "\t" << numbers[i] << "\t";

        for (int j = 0; j < numbers[i]; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

// ==================================================
// Task 4: Print a 2D array using a function
// ==================================================
void printArray(int a[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void task4() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printArray(a, 2);
}

// ==================================================
// Main: Uncomment exactly one task call to execute it
// ==================================================
int main() {
    task1();       // Task 1 runs by default

    // task2();    // Uncomment to run Task 2
    // task3();    // Uncomment to run Task 3
    // task4();    // Uncomment to run Task 4

    return 0;
}
