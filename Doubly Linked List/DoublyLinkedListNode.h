class Node {
	int data; Node *next, *previous;

	public:

	Node(int val) { data = val; next = NULL; previous = NULL; }

	void setData(int val) { data = val; }
	int getData() { return data; }

	void setNext(Node* link) { next = link; }
	Node* getNext() { return next; }

	void setPrevious(Node* link) { previous = link; }
	Node* getPrevious() { return previous; }
};
