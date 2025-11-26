#include <iostream>
#include "Node.h"
#include "Stack.h"

using namespace std;

int main() {
  Stack stack;
  int ip, i;
  bool stk = true;
  while (stk) {
    cout << "0. Exit\n1. Push\n2. Pop\n3. Clear";
    cin >> i;
    switch (i) {
      case 0: stk = false;
        break;
      case 1: cout << "Enter a number: ";
        cin >> ip;
        stack.push(ip);
        break;
      case 2: stack.pop();
        break;
      case 3: stack.clear();
        break;
      default: cout << "Invalid input" << endl;
    }
  }
}
