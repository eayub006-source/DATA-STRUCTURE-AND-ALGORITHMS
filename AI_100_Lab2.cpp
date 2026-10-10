#include <iostream>
#include <string>
using namespace std;

// ==================================================
// Task 1: Exchange of Scores using pointers
// ==================================================
void swapScores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void task1() {
    int first, second;

    cout << "Enter the first value = ";
    cin >> first;
    cout << "Enter the second value = ";
    cin >> second;

    swapScores(&first, &second);

    cout << "\\nVALUES AFTER EXCHANGE" << endl;
    cout << "First value = " << first << endl;
    cout << "Second Value = " << second << endl;
}

// ==================================================
// Task 2: Weather Report Converter using pointers
// ==================================================
void fahrenheitToCelsius(float* fahrenheit, float* celsius) {
    *celsius = (*fahrenheit - 32) * 5.0 / 9.0;
}

void task2() {
    float fahrenheit, celsius;

    cout << "Enter the temperature in fahrenheit = ";
    cin >> fahrenheit;

    fahrenheitToCelsius(&fahrenheit, &celsius);

    cout << "Temperature in celcius = " << celsius << endl;
}

// ==================================================
// Task 3: Student Record Card using a structure
// ==================================================
struct Student {
    string name;
    int roll;
    float marks;
};

void task3() {
    Student s;

    cout << "Enter name: ";
    getline(cin >> ws, s.name);

    cout << "Enter roll no: ";
    cin >> s.roll;

    cout << "Enter marks: ";
    cin >> s.marks;

    cout << "\\n------ STUDENT RECORD ------" << endl;
    cout << "Name : " << s.name << endl;
    cout << "Roll : " << s.roll << endl;
    cout << "Marks : " << s.marks << endl;
}

// ==================================================
// Main: Uncomment exactly one task call to execute it
// ==================================================
int main() {
    task1();       // Task 1 runs by default

    // task2();    // Uncomment to run Task 2
    // task3();    // Uncomment to run Task 3

    return 0;
}
