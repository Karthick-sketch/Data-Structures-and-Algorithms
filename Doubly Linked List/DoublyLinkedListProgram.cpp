#include <iostream>
#include "DoublyLinkedListNode.h"
#include "DoublyLinkedList.h"

using namespace std;

int main() {
	int n, ip, afv;
	DoublyLinkedList dl;
	do {
		cout << "0. Close\n1. Insert at front\n2. Insert at End" << endl;
		cout << "3. Insert after a value\n4. Display" << endl;
		cin >> n;
		switch(n) {
			case 0: break;
			case 1: cout << "Enter a value: "; cin >> ip;
				dl.InsertFront(ip); break;
			case 2: cout << "Enter a value: "; cin >> ip;
				dl.InsertEnd(ip); break;
			case 3: cout << "Enter the value: "; cin >> afv;
				cout << "Enter a value to insert: "; cin >> ip;
				dl.InsertAfterValue(ip, afv); break;
			case 4: dl.display(); break;
			default: cout << "Invalid input" << endl;
		}
	} while (n != 0);
	cout << "Done" << endl;
}
