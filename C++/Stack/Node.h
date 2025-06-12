class Node {
  int value;
  Node *next;

  public:
  Node(int value) {
    this->value = value;
    this->next = NULL;
  }

  void setValue(int value) {
    this->value = value;
  }

  int getValue() {
    return value;
  }

  void setNext(Node* next) {
    this->next = next;
  }

  Node* getNext() {
    return next;
  }
};
