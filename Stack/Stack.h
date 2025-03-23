class Stack {
	Node *top;

	public:

	Stack() {
		top = NULL;
	}

	void push(int value) {
		Node *node = new Node(value);
		if (top != NULL) {
			node->setNext(top);
		}
		top = node;
	}

	int pop() {
    int value = 0;
		if (top != NULL) {
			Node* currentNode = top;
			top = top->getNext();
			value = currentNode->getValue();
			delete currentNode;
		}
    return value;
	}

  void clear() {
    Node* currentNode = top;
    while (currentNode != NULL) {
      top = top->getNext();
      delete currentNode;
      currentNode = top;
    }
  }

	~Stack() {
		clear();
	}
};
