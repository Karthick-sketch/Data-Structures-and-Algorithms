#include <iostream>
#include "SinglyLinkedListNode.h"
#include "Queue.h"

using namespace std;

int main() {
	Queue q;
	int ip, value;
	bool loop = true;

	do {
		cout << "0. Exit\n1. Enqueue\n2. Dequeue\n3. Clear\n> ";
    cin >> ip;
		if (ip == 1) {
			cout << "Enter a number: ";
      cin >> value;
			q.enqueue(value);
		} else if (ip == 2)	{
      cout << q.dequeue() << endl;
    }
		else if (ip == 3) {
      q.clear();
    }
    cout << endl;
	} while (ip != 0);
}
