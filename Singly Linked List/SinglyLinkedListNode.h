class Node {
	int data;
  Node *next;

public:
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  void setLink(Node* link) {
    next = link;
  }

  Node* getLink() {
    return next;
  }

  void setData(int data) {
    this->data = data;
  }

  int getData() {
    return data;
  }
};
