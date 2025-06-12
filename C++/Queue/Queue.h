class Queue {
  Node *front, *rear;

public:
  Queue() {
    front = rear = NULL;
  }

  void enqueue(int value) {
    Node *node = new Node(value);
    if (front == NULL) {
      front = node;
    } else {
      rear->setNext(node);
    }
    rear = node;
    std::cout << "Enqueued" << std::endl;
  }

  void dequeue() {
    if (front == NULL) {
      std::cout << "Queue is empty" << std::endl;
      rear = NULL;
    } else {
      Node* temp = front;
      front = front->getNext();
      std::cout << temp->getValue() << std::endl;
      delete temp;
      std::cout << "Dequeued" << std::endl;
    }
  }	

  void print() {
    Node* temp = front;
    std::cout << "[ ";
    while (temp != NULL) {
      std::cout << temp->getValue() << ' ';
      temp = temp->getNext();
    }
    std::cout << ']' << std::endl;
  }

  void clear() {
    Node* temp = NULL;
    while (front != NULL) {
      temp = front;
      front = front->getNext();
      delete temp;
    }
    rear = NULL;
  }

  ~Queue() {
    clear();
  }
};
