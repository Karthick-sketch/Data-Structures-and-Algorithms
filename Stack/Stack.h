class Stack{
  Node *top;

public:
  Stack() {
    top = NULL;
  }

  void push(int value) {
    Node *node = new Node(value);
    if (top != NULL) {
      node->setNext(top);
    }
    top = node;
    std::cout << "Pushed" << std::endl;
  }

  void pop() {
    if (top == NULL) {
      std::cout << "Stack is empty" << std::endl;
    } else {
      Node* crnd = top;
      top = top->getNext();
      std::cout << crnd->getValue() << " is Popped" << std::endl;;
      delete crnd;
    }
  }

  void clear() {
    if (top != NULL) {
      Node* crnd = NULL;
      while (top != NULL) {
        crnd = top;
        top = top->getNext();
        delete crnd;
      }
    }
  }

  ~Stack() {
    clear();
  }
};
