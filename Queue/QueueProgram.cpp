#include <iostream>
#include "SinglyLinkedList.h"
#include "Queue.h"

using namespace std;

int main() {
	Queue queue;
	int ip, value;
	bool loop = true;
	while (loop) {
		cout << "0. Exit\n1. Enqueue\n2. Dequeue\n3. Clear" << endl; cin >> ip;
		switch (ip) {
			case 0: loop = false; break;
			case 1: cout << "Enter a number: "; cin >> value;
				queue.enqueue(value); break;
			case 2: queue.dequeue(); break;
			case 3: queue.clear(); break;
			default: cout << "Invalid Input" << endl;
		}
	}
}
