template <typename T>
class Iterator {
    Node<T> *node;

    public:
    Iterator(Node<T> *n) { setIterator(n); }

    void operator = (Node<T> *n) { setIterator(n); }

    void setIterator(Node<T> *n) { node = n; }

    bool hasNext() { return node != NULL; }

    T next() {
        T data = node->getData();
        node = node->getNextNode();
        return data;
    }
};
