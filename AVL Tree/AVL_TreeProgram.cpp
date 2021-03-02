#include <iostream>
#include <time.h>
#include "BinaryTreeNode.h"
#include "AVL_Tree.h"
using namespace std;
int main() {
	srand(time(0));

	int num, ip;

	AVLTree avl;

	do {
		cout << "\n0. Close\n1. Insert\n2. Insert random numbers\n3. Search" << endl;
		cout << "4. Largest number\n5. Lowest number\n6. Print" << endl;
		cout << "7. Delete\nPlease select the number: " << endl;
		cin >> num;

		switch(num) {
			case 0: break;
			case 1: cout << "Enter number of values to insert: ";	cin >> ip;
				for (int i = 0, val;i < ip;i++) {	cin >> val;	avl.insert(val);	}
				cout << "Inserted" << endl;	break;
			case 2: cout << "Enter the number of values: ";	cin >> ip;
				cout << "[";
				for (int i = 0, val;i < ip;i++) {
					val = rand()%1000;
					cout << ip << ((i < ip-1) ? ", " : "]\n");
					avl.insert(val);
				}
				cout << "Inserted" << endl;	break;
			case 3:	cout << "Enter the number: ";	cin >> ip;
				Node* v;	v = avl.search(ip, true);
				if (v == NULL)	cout << ip << " is not in the tree" << endl;
				else	cout << ip << "'s address is " << v << endl;
				break;
			case 4: cout << "Largest number: " << avl.maximum() << endl;	break;
			case 5: cout << "Lowest number: " << avl.minimum() << endl;	break;
			case 6: avl.display();	break;
			case 7: cout << "Enter the number to remove: ";
				cin >> ip;	avl.Delete(ip);
				break;
			default: cout << "Invalid input" << endl;
		}
	} while (num != 0);
}