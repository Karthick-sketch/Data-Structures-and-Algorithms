class Node {
	int data;
	Node *left, *right;

	public:

	Node(int val) {	data = val;	left = NULL;	right = NULL;	}

	void setData(int val) {  data = val; }
	int getData() { return data;  }

	void setLeft(Node* link) {  left = link;  }
	Node* getLeft() { return left;  }

	void setRight(Node* link) {  right = link;  }
	Node* getRight() { return right;  }
};