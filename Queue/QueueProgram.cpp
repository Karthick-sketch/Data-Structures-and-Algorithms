#include <iostream>
#include "SinglyLinkedList.h"
#include "Queue.h"
using namespace std;
int main() {
	Queue q;
	int ip, value;
	bool loop = true;
	while (loop) {
		cout << "0. Exit\n1. Enqueue\n2. Dequeue" << endl; cin >> ip;
		if (ip == 0) loop = false;
		else if (ip == 1) {
			cout << "Enter a number: "; cin >> value;
			q.Enqueue(value);
		} else if (ip == 2)	q.Dequeue();
		else cout << "Invalid Input" << endl;
	}
}
