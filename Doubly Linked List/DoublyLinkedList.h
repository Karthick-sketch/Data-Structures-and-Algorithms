class DoublyLinkedList {
	Node *head, *tail;

	public:

	DoublyLinkedList() {	head = NULL;	tail = NULL;	}
	
	void InsertFront(int val) {
		Node* node = new Node(val);
		if (head != NULL) {
			node->setNext(head);
			head->setPrevious(node);
		}
		else	tail = node;
		head = node;
		std::cout << "Done" << std::endl;
	}
	
	void InsertEnd(int val) {
		Node* node = new Node(val);
		if (tail != NULL) {
			tail->setNext(node);
			node->setPrevious(tail);
		}
		else	head = node;
		tail = node;
		std::cout << "Done" << std::endl;
	}
	
	void InsertAfterValue(int vl, int afv) {
		Node* crnd = head;
		if (head != NULL) {
			Node* node = new Node(vl);
			if (tail->getData() == afv) {
				tail->setNext(node);
				node->setPrevious(tail);
				tail = node;
			}
			else {
				while (crnd->getData() != afv && crnd->getNext() != NULL)
					crnd = crnd->getNext();

				if (crnd->getData() == afv) {
					node->setNext(crnd->getNext());
					node->setPrevious(crnd);
					crnd->setNext(node);
					crnd = node->getNext();
					crnd->setPrevious(node);
					if (node->getNext() == NULL)	tail = node;
				}
				else	std::cout << afv << " is not there in this list" << std::endl;
			}
		}
		else	std::cout << "No list found" << std::endl; 
	}
	
	void display() {
		Node *crnd = head, *prend = tail;
		if (crnd != NULL && prend != NULL) {
			std::cout << "Traversing by next" << std::endl;
			while (crnd != NULL) {
				std::cout << crnd->getData();
				crnd = crnd->getNext();
				if (crnd != NULL)	std::cout << " -> ";
			}
			std::cout << std::endl << "Traversing by previous" << std::endl;
			while (prend != NULL) {
				std::cout << prend->getData();
				prend = prend->getPrevious();
				if (prend != NULL)	std::cout << " <- ";
			}
			std::cout << std::endl;
		}
		else	std::cout << "List is empty" << std::endl;
	}
};