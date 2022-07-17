class Stack{
	Node *top;

	public:

	Stack() { top = NULL; }

	void push(int vl) {
		Node *node = new Node(vl);
		if (top != NULL) {
			node->setLink(top);
		}
		top = node;
		std::cout << "Pushed" << std::endl;
	}

	void pop() {
		if (top == NULL) std::cout << "Stack is empty" << std::endl;
		else {
			Node* crnd = top;
			top = top->getLink();
			std::cout << crnd->getData();
			delete crnd;
			std::cout << " is Popped" << std::endl;
		}
	}

	void clear() {
		if (top != NULL) {
			Node* crnd = NULL;
			while (top != NULL) {
				crnd = top;
				top = top->getLink();
				delete crnd;
			}
		}
	}

	~Stack() { clear(); }
};
