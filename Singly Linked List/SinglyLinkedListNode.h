class Node {
	int data;
	Node *next;

	public:

	Node(int vl) {	data = vl;	next = NULL;	}

	void setData(int val) {  data = val; }
	int getData() { return data;  }

	void setLink(Node* link) {  next = link;  }
	Node* getLink() { return next;  }
};