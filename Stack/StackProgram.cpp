#include <iostream>
#include "SinglyLinkedListNode.h"
#include "Stack.h"

using namespace std;

int main() {
	Stack st;
	int ip, i;

	do {
		cout << "0. Exit\n1. Push\n2. Pop\n3. Clear\n> ";
    cin >> i;
		if (i == 1) {
			cout << "Enter a number: ";
      cin >> ip;
			st.push(ip);
		} else if (i == 2) {
      cout << st.pop() << endl;
    }
		else if (i == 3) {
      st.clear();
    }
    cout << endl;
	} while (i != 0);
}
