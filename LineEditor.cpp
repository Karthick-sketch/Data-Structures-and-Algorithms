#include <iostream>
#include <sstream>
#include "./LinkedList/LinkedList.h"

using namespace std;

LinkedList<string> list;

void print() {
    int ln = 0;
    while (true) {
        cout << endl << ln+1 << '.';
        if (ln < list.length()) {
            cout << list.get(ln++);
        } else { break; }
    }
    cout << endl << endl;
}

void write() {
    string text;
    getline(cin, text);
    list.push(text);
}

void cut() {
    int from, to;
    cin >> from >> to;
    list.insert(to-1, list.get(from-1));
}

void copy() {
    int from, to;
    cin >> from >> to;
    string text = list.get(--from);
    list.removeAt(from);
    list.insert(to-1, text);
}

void remove() {
    int pos; cin >> pos;
    list.removeAt(pos-1);
}

int main() {
    int from, to;
    
    print();
    char input; cin >> input;
    while (input != 'e') {
        switch (input) {
            case 'w': write(); break;
            case 'x': cut(); break;
            case 'c': copy(); break;
            case 'r': remove(); break;
        }
        print();
        cin >> input;
    }

    return 0;
}
