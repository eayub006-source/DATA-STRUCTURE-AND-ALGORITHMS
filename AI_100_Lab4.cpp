#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// ============================================================
// Task 1: Count nodes in a singly linked list using size()
// ============================================================
struct SNode {
    int data;
    SNode* next;
    SNode(int value) : data(value), next(nullptr) {}
};

class SinglyList {
private:
    SNode* head;
    SNode* tail;

public:
    SinglyList() : head(nullptr), tail(nullptr) {}

    void insertAtTail(int value) {
        SNode* n = new SNode(value);
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void display() const {
        SNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << '\n';
    }

    int size() const {
        int count = 0;
        for (SNode* current = head; current != nullptr; current = current->next) {
            count++;
        }
        return count;
    }

    // Task 2: Swap two nodes by changing links, not their data.
    bool swapNodes(int x, int y) {
        if (x == y) return true;

        SNode *prevX = nullptr, *currX = head;
        while (currX != nullptr && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        SNode *prevY = nullptr, *currY = head;
        while (currY != nullptr && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (currX == nullptr || currY == nullptr) return false;

        // Make currX the node that appears first in the list.
        if (prevY == currX) {
            SNode* temp = currX; currX = currY; currY = temp;
            SNode* tempPrev = prevX; prevX = prevY; prevY = tempPrev;
        }
        if (prevX == currY) {
            SNode* temp = currX; currX = currY; currY = temp;
            SNode* tempPrev = prevX; prevX = prevY; prevY = tempPrev;
        }

        // Handle adjacent nodes separately.
        if (currX->next == currY) {
            if (prevX != nullptr) prevX->next = currY;
            else head = currY;
            currX->next = currY->next;
            currY->next = currX;
        } else if (currY->next == currX) {
            if (prevY != nullptr) prevY->next = currX;
            else head = currX;
            currY->next = currX->next;
            currX->next = currY;
        } else {
            if (prevX != nullptr) prevX->next = currY;
            else head = currY;
            if (prevY != nullptr) prevY->next = currX;
            else head = currX;
            SNode* tempNext = currX->next;
            currX->next = currY->next;
            currY->next = tempNext;
        }

        // Recalculate tail so the list remains correct.
        tail = head;
        if (tail != nullptr) while (tail->next != nullptr) tail = tail->next;
        return true;
    }

    // Task 3: Recursive traversal.
    static void showRecursive(SNode* current) {
        if (current == nullptr) return;
        cout << current->data;
        if (current->next != nullptr) cout << " ";
        showRecursive(current->next);
    }

    void recursiveDisplay() const {
        showRecursive(head);
        cout << '\n';
    }

    SNode* getHead() const { return head; }

    ~SinglyList() {
        SNode* current = head;
        while (current != nullptr) {
            SNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

void task1() {
    cout << "Task 1: size()\n";
    SinglyList list;
    list.insertAtTail(25);
    list.insertAtTail(50);
    list.insertAtTail(90);
    cout << "List: ";
    list.display();
    cout << "Size: " << list.size() << '\n';
}

void task2() {
    cout << "Task 2: Swap nodes without swapping data\n";
    SinglyList list;
    for (int value : {25, 50, 90, 40, 70}) list.insertAtTail(value);
    cout << "Before: "; list.display();
    if (list.swapNodes(50, 40)) {
        cout << "After swapping nodes 50 and 40: ";
        list.display();
    } else {
        cout << "One or both values were not found.\n";
    }
}

void task3() {
    cout << "Task 3: Recursive linked-list traversal\n";
    SinglyList list;
    for (int value : {25, 50, 90}) list.insertAtTail(value);
    cout << "Recursive traversal: ";
    list.recursiveDisplay();
}

// ============================================================
// Task 4: Garage road and garage as stacks (last-in, first-out).
// Input commands are typed one per line; type END to finish.
// ============================================================
void task4() {
    vector<int> road;
    vector<int> garage;
    string command;

    cout << "Task 4: Truck garage simulation\n";
    cout << "Commands: On_road id | Enter_garage id | Exit_garage id | "
            "Show_trucks road | Show_trucks garage | END\n";

    while (true) {
        cout << "> ";
        if (!(cin >> command)) break;
        if (command == "END") break;

        int id;
        if (command == "On_road") {
            if (!(cin >> id)) break;
            if (id <= 0) {
                cout << "Truck ID must be a positive integer.\n";
                continue;
            }
            road.push_back(id);
        } else if (command == "Enter_garage") {
            if (!(cin >> id)) break;
            auto it = find(road.begin(), road.end(), id);
            if (it == road.end()) {
                cout << "Truck " << id << " not on road\n";
            } else {
                road.erase(it);
                garage.push_back(id);
            }
        } else if (command == "Exit_garage") {
            if (!(cin >> id)) break;
            if (garage.empty() || garage.back() != id) {
                cout << "Truck " << id << " not near garage door\n";
            } else {
                garage.pop_back();
            }
        } else if (command == "Show_trucks") {
            string where;
            if (!(cin >> where)) break;
            const vector<int>* selected = nullptr;
            if (where == "road") selected = &road;
            else if (where == "garage") selected = &garage;
            else {
                cout << "Use road or garage.\n";
                continue;
            }
            cout << where << ": ";
            if (selected->empty()) cout << "(empty)";
            else {
                for (size_t i = 0; i < selected->size(); ++i) {
                    if (i) cout << " ";
                    cout << (*selected)[i];
                }
            }
            cout << '\n';
        } else {
            cout << "Unknown command.\n";
        }
    }
}

// ============================================================
// Task 5: Two circular doubly linked lists and elimination game.
// Assumption: names.txt contains two lines. Each line contains
// names separated by spaces: first list on line 1, second on line 2.
// The second list starts counting at index floor(n/2), clockwise.
// ============================================================
struct DNode {
    string name;
    DNode* next;
    DNode* prev;
    explicit DNode(const string& value) : name(value), next(this), prev(this) {}
};

class CircularDoublyList {
private:
    DNode* head;
    int count;

public:
    CircularDoublyList() : head(nullptr), count(0) {}

    void append(const string& name) {
        DNode* n = new DNode(name);
        if (head == nullptr) {
            head = n;
        } else {
            DNode* tail = head->prev;
            tail->next = n;
            n->prev = tail;
            n->next = head;
            head->prev = n;
        }
        count++;
    }

    int size() const { return count; }
    DNode* getHead() const { return head; }

    void display() const {
        if (head == nullptr) {
            cout << "(empty)";
            return;
        }
        DNode* current = head;
        do {
            cout << current->name;
            current = current->next;
            if (current != head) cout << " ";
        } while (current != head);
    }

    // Remove a node and return the node that followed it.
    DNode* eliminate(DNode* target) {
        if (target == nullptr) return nullptr;
        if (count == 1) {
            delete target;
            head = nullptr;
            count = 0;
            return nullptr;
        }
        DNode* nextNode = target->next;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        if (target == head) head = nextNode;
        delete target;
        count--;
        return nextNode;
    }

    ~CircularDoublyList() {
        while (head != nullptr) eliminate(head);
    }
};

void task5() {
    cout << "Task 5: Circular doubly linked-list elimination game\n";
    ifstream file("names.txt");
    if (!file) {
        cout << "Could not open names.txt. Create the file using the format "
                "described in the report.\n";
        return;
    }

    string line;
    vector<string> firstNames, secondNames;
    if (getline(file, line)) {
        istringstream in(line);
        string name;
        while (in >> name) firstNames.push_back(name);
    }
    if (getline(file, line)) {
        istringstream in(line);
        string name;
        while (in >> name) secondNames.push_back(name);
    }

    if (firstNames.empty() || secondNames.empty()) {
        cout << "The file must contain at least one name on each of its first two lines.\n";
        return;
    }

    CircularDoublyList firstList, secondList;
    for (const string& name : firstNames) firstList.append(name);
    for (const string& name : secondNames) secondList.append(name);

    cout << "Initial first list: "; firstList.display(); cout << '\n';
    cout << "Initial second list: "; secondList.display(); cout << '\n';

    int m = firstList.size();
    DNode* current = secondList.getHead();
    for (int i = 0; i < (int)secondNames.size() / 2; ++i) current = current->next;

    // Repeat at most m eliminations; count m nodes clockwise each round.
    for (int round = 0; round < m && secondList.size() > 0; ++round) {
        for (int step = 1; step < m; ++step) current = current->next;
        current = secondList.eliminate(current);
    }

    cout << "Final second list: "; secondList.display(); cout << '\n';
}

int main() {
    // Only Task 1 is active by default. Uncomment ONE task call at a time.
    task1();

    // task2();
    // task3();
    // task4();
    // task5();

    return 0;
}
