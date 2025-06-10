class Node {
  int data;
  Node *next, *previous;

public:
  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->previous = NULL;
  }

  void setData(int data) {
    this->data = data;
  }

  int getData() {
    return data;
  }

  void setNext(Node* link) {
    next = link;
  }

  Node* getNext() {
    return next;
  }

  void setPrevious(Node* link) {
    previous = link;
  }

  Node* getPrevious() {
    return previous;
  }
};
