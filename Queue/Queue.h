class Queue {
	Node *front, *rear;

	public:

	Queue() { front = NULL; rear = NULL; }

	void enqueue(int vl) {
		Node *node = new Node(vl);
		if (front == NULL) front = node;
		else rear->setLink(node);
		rear = node;
		std::cout << "Enqueued" << std::endl;
	}

	void dequeue() {
		if (front == NULL) {
			std::cout << "Queue is empty" << std::endl;
			rear = NULL;
		} else {
			Node* temp = front;
			front = front->getLink();
			std::cout << temp->getData() << std::endl;
			delete temp;
			std::cout << "Dequeued" << std::endl;
		}
	}

	void clear() {
		Node* temp = NULL;
		while (front != NULL) {
			temp = front;
			front = front->getLink();
			delete temp;
		}
		rear = NULL;
	}

	~Queue() { clear(); }
};
