class Stack{
	Node *top;

	public:

	Stack() {	top = NULL;	}

	void Push(int vl) {
		Node *node = new Node(vl);
		if (top == NULL)	top = node;
		else {
			Node* crnd = top;
			node->setLink(crnd);
			top = node;
		}
		std::cout << "Pushed" << std::endl;
	}

	void Pop() {
		if (top == NULL)	std::cout << "Stack is empty" << std::endl;
		else {
			Node* crnd = top;
			top = top->getLink();
			std::cout << crnd->getData();
			delete crnd;
			std::cout << " is Popped" << std::endl;
		}
	}

	~Stack() {
		if (top != NULL) {
			Node* crnd = NULL;
			while (top != NULL) {
				crnd = top;
				top = top->getLink();
				delete crnd;
			}
		}
		std::cout << "Done";
	}
};