template<typename T> class Node {
	Node *next; T data;

	public:

	Node(T val) { data = val; next = NULL; }

	void setLink(Node* link) { next = link; }
	Node* getLink() { return next; }

	void setData(T val) { data = val; }
	T getData() { return data; }
};


template<typename T> class List {
	Node<T> *head, *tail;

	void exitProgram() { clear(); exit(0); }

	void exitProgram(std::string exception_message) {
		std::cout << "error: " << exception_message << std::endl;
		exitProgram();
	}

	void exitProgram(std::string exception_message, T val) {
		std::cout << "error: " << exception_message << "'" << val << "'" << std::endl;
		exitProgram();
	}

	// remove item and return its data
	T removeItem(Node<T> *ptr) {
		T val;
		if (ptr != NULL) {
			val = ptr->getData();
			remove(val);
		} else exitProgram("List is empty");
		return val;
	}

	public:

	List() { head = tail = NULL; }

	T operator [] (int index_number) { return get(index_number); }

	int length() {
        int len = 0;
        for (Node<T> *ptr = head;ptr != NULL;len++) {
            ptr = ptr->getLink();
        }
        return len;
    }

	T get(int index_number) {
		if (index_number < 0 || index_number >= length()) {
			exitProgram("List index out of range");
		}

		Node<T> *ptr = head;
		for (int ind = 0;ind != index_number;ind++) {
			ptr = ptr->getLink();
		}
		return ptr->getData();
	}

	void set(int index_number, T value) {
		if (index_number < 0 || index_number >= length()) {
			exitProgram("List index out of range");
		} else {
			Node<T> *ptr = head;
			for (int ind = 0;ind != index_number;ind++) {
				ptr = ptr->getLink();
			}
			ptr->setData(value);
		}
	}

	// adds new item to beginning of the list
	void unshift(T val) {
		Node<T> *node = new Node<T>(val);
		if (head != NULL) node->setLink(head);
		head = node;
		if (tail == NULL) tail = head;
	}

	// remove the first item from the list
	T shift() { return removeItem(head); }

	// add new item to end of the list
	void push(T val) {
		Node<T> *node = new Node<T>(val);
		if (head == NULL) head = node;
		else tail->setLink(node);
		tail = node;
	}

	// remove the last item from the list
	T pop() { return removeItem(tail); }

	// returns index number from the given value
	int index(T val) {
		int index_number = 0;
		Node<T> *ptr = head;
		while (ptr != NULL && ptr->getData() != val) {
			index_number++;
			ptr = ptr->getLink();
		}

		if (ptr == NULL) {
			exitProgram("Unable to find the value ", val);
		}
		return index_number;
	}

	// adds a value after the given index number
	void insert(int pos, T val) {
		if (pos < 0) exitProgram("Invalid index number");
		else if (pos == 0) unshift(val);
		else if (pos >= length()) push(val);
		else {
			Node<T> *crnd = head;
			for (int i = 1;i != pos;i++) {
				crnd = crnd->getLink();
			}
			Node<T> *node = new Node<T>(val);
			node->setLink(crnd->getLink());
			crnd->setLink(node);
		}
	}

	// search the given value from the list
	bool search(T val) {
		bool exists = false;
		Node<T> *temp = head;
		while (temp != NULL && !exists) {
			if (temp->getData() == val) exists = true;
			else temp = temp->getLink();
		}
		return exists;
	}

	// remove a value from the given index number from the list
	void removeAt(int pos) {
		if (pos >= 0 && pos < length()) {
			Node<T> *current_node = head, *previous_node = NULL;
			for (int i = 0;i != pos;i++) {
				previous_node = current_node;
				current_node = current_node->getLink();
			}
			if (current_node == head) head = current_node->getLink();
			else if (current_node == tail) {
				tail = previous_node;
				tail->setLink(NULL);
			} else previous_node->setLink(current_node->getLink());
			delete current_node;
		}
	}

	// remove the given value from the list
	void remove(T val) { removeAt(index(val)); }

	// sort the current list
	void sort() {
		bool sorted = false;
		for (int i = 0;i < length() && !sorted;i++) {
			sorted = true;
			for (int j = 0;j < length()-i-1;j++) {
				if (get(j) > get(j+1)) {
					int temp = get(j);
					set(j, get(j+1));
					set(j+1, temp);
					sorted = false;
				}
			}
		}
	}

	// reverse a list
	void reverse() {
		for (int i = 0, j = length()-1; i < j;i++, j--) {
			T temp = get(j);
			set(j, get(i));
			set(i, temp);
		}
	}

	// removes duplicate values from a list
	void uniq() {
		for (int i = 0;i < length();i++) {
			for (int j = 0;j < i;j++) {
				if (get(j) == get(i)) removeAt(i--);
			}
		}
	}

	// delete all existing nodes
	void clear() {
		Node<T> *ptr = head;
		while (head != NULL) {
			head = head->getLink();
			delete ptr;
			ptr = head;
		}
		tail = NULL;
	}

	std::string join(std::string joiner) {
		std::stringstream stream;
		for (int i = 0;i < length();++i) {
			if (i) stream << joiner;
			stream << get(i);
		}
		return stream.str();
	}

	// delete all existing nodes when exiting the program
	~List() { clear(); }
};
