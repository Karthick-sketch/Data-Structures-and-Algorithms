#include <iostream>
#include <time.h>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"

using namespace std;

int main() {
  srand(time(0));
  int num, ip;
  BinarySearchTree bt;

  do {
    cout << "\n0. Close\n1. Insert\n2. Insert random numbers" << endl;
    cout << "3. Search\n4. Largest number\n5. Lowest number" << endl;
    cout << "6. Print\n7. Remove\n8. Clear" << endl;
    cout << "Please select the number: " << endl;
    cin >> num;

    switch(num) {
      case 0: break;
      case 1: cout << "Enter number of values to insert: ";
        cin >> ip;
        for (int i = 0, val; i < ip; i++) {
          cin >> val;
          bt.insert(val);
        }
        cout << "Inserted" << endl;
        break;
      case 2: cout << "Enter the number of values: ";
        cin >> ip;
        cout << "[";
        for (int i = 0, val; i < ip; i++) {
          val = rand()%1000;
          cout << val << ((i < ip-1) ? ", " : "]\n");
          bt.insert(val);
        }
        cout << "Inserted" << endl;
        break;
      case 3:	cout << "Enter the number: ";
        cin >> ip;
        if (bt.search(ip)) {
          cout << ip << " is exists in the tree" << endl;
        } else {
          cout << ip << " is not in the tree" << endl;
        }
        break;
      case 4: cout << "Largest number: " << bt.maximum() << endl;
        break;
      case 5: cout << "Lowest number: " << bt.minimum() << endl;
        break;
      case 6: bt.print();
        break;
      case 7: cout << "Enter the number to remove: ";
        cin >> ip;
        bt.remove(ip);
        break;
      case 8: bt.clear();
        cout << "Cleared" << endl;
        break;
      default: cout << "Invalid input" << endl;
    }
  } while (num != 0);
}
