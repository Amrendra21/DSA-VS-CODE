#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;   // fixed hash table size

vector<deque<int>> table(SIZE);   // 10 buckets

int hashFunction(int key) {
    return key % SIZE;
}

void insertElement(int key) {
    int idx = hashFunction(key);
    table[idx].push_back(key);
    cout << key << " inserted!\n";
}

void deleteElement(int key) {
    int idx = hashFunction(key);
    auto &dq = table[idx];

    auto it = find(dq.begin(), dq.end(), key);
    if (it != dq.end()) {
        dq.erase(it);
        cout << key << " deleted!\n";
    } else {
        cout << key << " not found!\n";
    }
}

void searchElement(int key) {
    int idx = hashFunction(key);
    auto &dq = table[idx];

    auto it = find(dq.begin(), dq.end(), key);
    if (it != dq.end())
        cout << key << " found in bucket " << idx << "!\n";
    else
        cout << key << " not found!\n";
}

void displayTable() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> ";
        for (int x : table[i]) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    int choice, x;

    while (true) {
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                insertElement(x);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> x;
                deleteElement(x);
                break;
            case 3:
                cout << "Enter element: ";
                cin >> x;
                searchElement(x);
                break;
            case 4:
                displayTable();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
