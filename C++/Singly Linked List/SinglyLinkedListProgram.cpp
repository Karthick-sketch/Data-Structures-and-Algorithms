#include <iostream>
#include <time.h>
#include "SinglyLinkedList.h"
using namespace std;

void insert(LinkedList* list) {
  cout << "0. Close\n1. Insert at Front\n2. Insert at End\n3. Insert after a value\n";
  cout << "4. Insert before a value\n5. Insert after position\n6. Insert before position\n7. Insert Random numbers\n";
  int ip, src;  cin >> ip;
  switch(ip) {
    case 0: break;
    case 1:	cout << "Enter a value: "; cin >> ip;
      list->insertAtFront(ip);
      cout << "Done" << endl;
      break;
    case 2:	cout << "Enter a value: "; cin >> ip;
      list->insertAtEnd(ip);
      cout << "Done" << endl;
      break;
    case 3:	cout << "Enter a node value: "; cin >> src;
      cout << "Enter a value: "; cin >> ip;
      list->insertAfterValue(ip, src);
      cout << "Done" << endl;
      break;
    case 4:	cout << "Enter a node value: "; cin >> src;
      cout << "Enter a value: "; cin >> ip;
      list->insertBeforeValue(ip, src);
      cout << "Done" << endl;
      break;
    case 5:	cout << "Enter position number: "; cin >> src;
      cout << "Enter a value: "; cin >> ip;
      list->insertAfterPosition(ip, src);
      cout << "Done" << endl;
      break;
    case 6:	cout << "Enter position number: "; cin >> src;
      cout << "Enter a value: "; cin >> ip;
      list->insertBeforePosition(ip, src);
      cout << "Done" << endl;
      break;
    case 7:	cout << "Enter the number of values: "; cin >> ip;
      for (int i = 0; i < ip; i++) {
        list->insertAtEnd(rand()%100);
      }
      cout << "Done" << endl;
      break;
    default: cout << "Invalid input" << endl;
  }
}

int main() {
  srand(time(0));
  LinkedList* list = new LinkedList();
  int ter, ip, src; //ter - terminate; ip - input; src - search;
  Node* p = NULL;
  do {
    cout << "0. Close\n1. Insert\n2. Search\n3. Delete\n";
    cout << "4. Display the length of the list\n5. Display\n6. Sort\n";
    cin >> ter;
    switch(ter) {
      case 0:	break;
      case 1:	insert(list);
        break;
      case 2:	cout << "Enter the number to find: ";
        cin >> ip;	p = list->search(ip);
        if (p != NULL) {
          cout << ip << "'s address is " << p << endl;
        }
        break;
      case 3:	cout << "Enter the number to delete: "; cin >> ip;
        list->remove(ip);
        break;
      case 4:	cout << "Length: " << list->length() << endl;
        break;
      case 5: list->print();
        break;
      case 6: list->sort();
        break;
      default: cout << "Invalid input" << endl;
    }
  } while(ter != 0);
  delete list;
}