template <typename T>
class Node {
	Node<T> *next_node; T data;

	public:
	Node(T val) { data = val; next_node = NULL; }

	void setNextNode(Node* node) { next_node = node; }
	Node* getNextNode() { return next_node; }

	void setData(T val) { data = val; }
	T getData() { return data; }
};
