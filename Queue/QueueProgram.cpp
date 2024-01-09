#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

int main() {
	Queue queue;
	int ip, value;
	bool loop = true;
	do {
		cout << "0. Exit\n1. Enqueue\n2. Dequeue" << endl;
		cout << "3. Print\n4. Clear" << endl;
		cout << "Please enter the number: "; cin >> ip;

		switch (ip) {
			case 0: loop = false;
				break;
			case 1: cout << "Enter a number: "; cin >> value;
				queue.enqueue(value);
				break;
			case 2: queue.dequeue();
				break;
			case 3: queue.print();
				break;
			case 4: queue.clear();
				cout << "Cleared" << endl;
				break;
			default: cout << "Invalid Input" << endl;
		}
	} while (loop);
}
