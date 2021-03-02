#include <iostream>
#include "SinglyLinkedList.h"
#include "Stack.h"
using namespace std;
int main() {
	Stack st;
	int ip, i;	bool stk = true;
	while (stk) {
		cout << "0. Exit\n1. Push\n2. Pop\n";	cin >> i;
		if (i == 1) {
			cout << "Enter a number: ";	cin >> ip;
			st.Push(ip);
		}
		else if (i == 2)	st.Pop();
		else if (i == 0)	stk = false;
		else	cout << "Invalid input" << endl;
	}
}