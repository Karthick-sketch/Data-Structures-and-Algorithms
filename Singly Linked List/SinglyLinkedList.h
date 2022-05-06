#include "SinglyLinkedListNode.h"

class LinkedList {
	Node *head, *tail;
	int len;

	public:

	LinkedList() {	head = NULL;	tail = NULL;	len = 0;	}

	int length() {  return len; }

	void InsertAtFront(int vl) {
		Node *node = new Node(vl);	len++;
		if (head != NULL) // if head is exists, we point head to node's next one
			node->setLink(head);
		head = node; // now we point head to node
		if (tail == NULL) // if tail is not exists, we point tail to head
			tail = head;
	}

	void InsertAtEnd(int vl) {
		Node *node = new Node(vl);	len++;
		if (head == NULL) // if head is not exists, we point head to node
			head = node;
		else
			tail->setLink(node); // we set node to tail's next one
		tail = node; // then we point tail to node
	}

	void InsertAfterValue(int vl, int afv) {
		if (head != NULL) {
			Node* crnd = head;
			while (crnd->getData() != afv && crnd->getLink() != NULL)
				crnd = crnd->getLink();
			if (crnd->getData() == afv) {
				Node *node = new Node(vl);	len++;
				node->setLink(crnd->getLink());
				crnd->setLink(node);
			}
			else
				std::cout << afv << " is not there in this list" << std::endl;
		}
		else
			std::cout << "No list found" << std::endl; 
	}

	void InsertBeforeValue(int vl, int bfv) {
		Node *prend;
		bool prendfnd = false;
		if (head != NULL) {
			Node* crnd = head;
			while (crnd->getData() != bfv && crnd->getLink() != NULL) {
				prend = crnd;
				crnd = crnd->getLink();
				prendfnd = true;
			}
			if (crnd->getData() == bfv) {
				Node *node = new Node(vl);	len++;
				node->setLink(crnd);
				if (prendfnd)
					prend->setLink(node);
				else
					head = node;
			}
			else
				std::cout << bfv << " is not there in this list" << std::endl;
		}
		else
			std::cout << "No list found" << std::endl; 
	}

	void InsertAfterPosition(int vl, int atp) {
		int i = 1;
		if (head != NULL) {
			Node* crnd = head;
			while (i != atp && crnd != NULL) {
				crnd = crnd->getLink();
				i++;
			}
			if (i == atp && crnd != NULL) {
				Node *node = new Node(vl);	len++;
				node->setLink(crnd->getLink());
				crnd->setLink(node);
			}
			else
				std::cout << "List is less than " << atp << std::endl;
		}
		else
			std::cout << "List is empty" << std::endl;
	}

	void InsertBeforePosition(int vl, int bfp) {
		int i = 1;
		Node *prend;
		bool prendfnd = false;
		if (head != NULL) {
			Node* crnd = head;
			while (i != bfp && crnd != NULL) {
				prend = crnd;
				crnd = crnd->getLink();
				prendfnd = true;
				i++;
			}
			if (i == bfp && crnd != NULL) {
				Node *node = new Node(vl);	len++;
				node->setLink(crnd);
				if (prendfnd)
					prend->setLink(node);
				else
					head = node;
			}
			else
				std::cout << bfp << " node is not there in this list" << std::endl;
		}
		else
			std::cout << "List is empty" << std::endl; 
	}

	Node* Search(int val) {
		Node* rtrn = NULL;
		if (head != NULL) {
			if (head->getData() == val)
				rtrn = head;
			else if (tail->getData() == val)
				rtrn = tail;
			else {
				Node* temp = head->getLink();
				bool run = true;
				while (temp != NULL && run) {
					if (temp->getData() == val) {
						rtrn = temp;
						run = false;
					}
					temp = temp->getLink();
				}
				if (run)
					std::cout << val << " is not exists in this list" << std::endl;
			}
		}
		else
			std::cout << "List is empty" << std::endl;
		return rtrn;
	}

	void Delete(int val) {
		if (head != NULL) {
			Node* crnd = NULL;
			Node* prend = head;
			if (head->getData() == val) {
				crnd = head;
				if (tail == head)
					tail = NULL;
				head = head->getLink();
				delete crnd;
				std::cout << "Deleted" << std::endl;
				len--;
			}
			else {
				bool run = true;
				crnd = head->getLink();
				while (crnd != NULL && run) {
					if (crnd->getData() == val) {
						if (crnd == tail) {
							prend->setLink(NULL);
							delete tail;
							tail = prend;
						}
						else {
							prend->setLink(crnd->getLink());
							delete crnd;
						}
						std::cout << "Deleted" << std::endl;
						len--;
						run = false;
					}
					prend = crnd;
					crnd = crnd->getLink();
				}
			}
		}
		else
			std::cout << "List is empty" << std::endl;
	}

	void Print() {
		Node *ptr = head;
		bool le = true;
		while (ptr != NULL) {
			std::cout << ptr->getData();
			ptr = ptr->getLink();
			if (ptr)
				std::cout << " -> ";
			le = false;
		}
		if (le)
			std::cout << "List is empty" << std::endl;
		else
			std::cout << std::endl;
	}

	void Sort() {
		int temp;
		bool isSort = false;

		for (int i = 0;i < len && !isSort;i++) {
			isSort = true;
			Node* left = head;
			Node* centre = head;
			Node* right = head->getLink();
			if (right != NULL) {
				for (int j = 0;j < len-i;j++) {
					if (right == NULL)
						j = len;
					else if (centre->getData() > right->getData()) { 
						if (left == centre)
							head = right;
						else
							left->setLink(right);
						centre->setLink(right->getLink());
						right->setLink(centre);
						if (right == tail) {
							tail = centre;
							j = len;
						}
						else
							j = 0;
						isSort = false;
						left = head;
						centre = head;
						right = head->getLink();
					}
					else {
						left = centre;
						centre = right;
						right = right->getLink();
					}
				}
			}
		}
		std::cout << "Sorted" << std::endl;
	}

	~LinkedList() {
		if (head != NULL) {
			Node* crnd = NULL;
			while (head != NULL) {
				crnd = head;
				head = head->getLink();
				delete crnd;
			}
		}
		std::cout << "Done" << std::endl;
	}
};
