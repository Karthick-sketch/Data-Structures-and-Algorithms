class Queue {
	Node *front, *rear;

	public:

	Queue() {
    front = NULL;
    rear = NULL;
  }

	void enqueue(int value) {
		Node *node = new Node(value);
		if (front == NULL) {
      front = node;
    } else {
      rear->setNext(node);
    }
		rear = node;
	}

	int dequeue() {
    int value = 0;
		if (front != NULL) {
			Node* temp = front;
			front = front->getNext();
			value = temp->getValue();
			delete temp;
		}
    return value;
	}

  void clear() {
    Node* temp = front;
		while (temp != NULL) {
			front = front->getNext();
			delete temp;
			temp = front;
		}
		rear = NULL;
  }

	~Queue() {
		clear();
	}
};
