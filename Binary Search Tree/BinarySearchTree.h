class BinaryTree {
	Node *root = NULL;

	void Print(Node* temp) {
		if (temp->getLeft() != NULL)
			Print(temp->getLeft());
		std::cout << temp->getData() << ", ";
		if (temp->getRight() != NULL)
			Print(temp->getRight());
	}

	public:

	BinaryTree() {	root = NULL;  }

	void Insert(int val) {
		Node* node = new Node(val);

		if (root == NULL)
			root = node;
		else {
			Node* leaf = root;
			bool leafexists = true;
			while (leafexists) {
				if (val < leaf->getData()) {
					if (leaf->getLeft() == NULL) {
						leaf->setLeft(node);	// if leaf->left is not exists leaf's left asigns a new node
						leafexists = false;
					}
					else	leaf = leaf->getLeft(); // if leaf->left is exists leaf traverse to left
				}
				else {
					if (leaf->getRight() == NULL) {
						leaf->setRight(node);	// if leaf->right is not exists leaf's right asigns a new node
						leafexists = false;
					}
					else	leaf = leaf->getRight(); // if leaf->right is exists leaf traverse to right
				}
			}
		}
	}

	void Delete(int val) {
		Node *child = root, *parent = NULL;
		bool exists = true;
		while (exists) {
			if (val == child->getData()) {
				if (child->getLeft() != NULL) {
					Node* temp1 = child->getLeft();
					Node* temp2 = temp1;
					while (temp1->getRight() != NULL) {
						temp2 = temp1;
						temp1 = temp1->getRight();
					}
					if (temp1->getLeft() != NULL) {
						if (temp1 != temp2)	temp2->setRight(temp1->getLeft());
						else {
							temp1->setRight(child->getRight());
							if (child == root) {
								root = temp1;	delete child;
								std::cout << val << " is deleted" << std::endl;	break;
							}
							else {
								parent->setRight(temp1);
								delete child;
								std::cout << val << " is deleted" << std::endl;	break;
							}
						}
					}
					else	temp2->setRight(NULL);
					child->setData(temp1->getData());
					if (child->getLeft() == temp1)	child->setLeft(NULL);
					delete temp1;  
				}
				else if (child->getRight() != NULL) {
					if (child == root)	root = child->getRight();
					else if (parent->getRight() == child)	parent->setRight((child->getLeft() != NULL) ? child->getLeft() : child->getRight());
					else	parent->setLeft((child->getLeft() != NULL) ? child->getLeft() : child->getRight());
					delete child;
				}
				else if (child == root) {	root = NULL;	delete child;	}
				else {
					(parent->getRight() == child) ? parent->setRight(NULL) : parent->setLeft(NULL);
					delete child;
				}
				std::cout << val << " is deleted" << std::endl;
				exists = false;
			}
			else if (val < child->getData()) {
				if (child->getLeft() == NULL) {
					exists = false;
					std::cout << val << " is not in the tree" << std::endl;
				}
				else {
					parent = child;
					child = child->getLeft();
				}
			}
			else {
				if (child->getRight() == NULL) {
					exists = false;
					std::cout << val << " is not in the tree" << std::endl;
				}
				else {
					parent = child;
					child = child->getRight();
				}
			}
		}
	}

	Node* Search(int val) {
		Node *tmp = root;
		bool isThere = true;
		Node* address = NULL; // if user input is not in the true it returns NULL

		while (isThere) {
			if (tmp != NULL && tmp->getData() == val) { // if user input is equal to tmp.data tmp's key value assignnd to ky
				isThere = false;
				address = tmp;
			}
			else if (val < tmp->getData()) {
				if (tmp->getLeft() == NULL)	isThere = false;
				else	tmp = tmp->getLeft();
			}
			else {
				if (tmp->getRight() == NULL)	isThere = false;
				else	tmp = tmp->getRight();
			}
		}
		return address;
	}

	int Maximum() { // in this function leaf goes to last left child in the tree, then it returns the minimum value
		Node* leaf = root;
		bool run = true;
		while (run) {
			if (leaf->getRight() == NULL)	run = false;
			else	leaf = leaf->getRight();
		}
		return leaf->getData();
	}

	int Minimum() { // in this function leaf goes to last right child in the tree, then it returns the maximum value
		Node* leaf = root;
		bool run = true;
		while (run) {
			if (leaf->getLeft() == NULL)	run = false;
			else	leaf = leaf->getLeft();
		}
		return leaf->getData();
	}

	void Print() {
		if (root != NULL) {
			std::cout << '[';
			Print(root);
			std::cout << "\b\b]" << std::endl;
		}
		else	std::cout << "[]" << std::endl;
	}

	~BinaryTree() {
		if (root != NULL) {
			Node *child, *parent;
			bool left = true, first = true, second = false;
	
			while (first) {
				child = root;
				parent = NULL;
				if (root->getLeft() == NULL && root->getRight() == NULL) {
					delete root;	// if root's all children are null, root will be deletnd
					first = false;
				}
				else	second = true;
	
				while(second) {
					if (child->getLeft() == NULL)	left = false; // left is false, then child goes to right
					else {
						parent = child;
						child = child->getLeft();
					}
	
					if (!left) {
						if (child->getRight() == NULL)	left = true; // if child->right is not exists left will become true, because we have to check next leaf
						else {
							parent = child;
							child = child->getRight();
						}
					}
	
					if (child->getLeft() == NULL && child->getRight() == NULL) {
						if (parent->getLeft() == child) { // parent->left is equal to child, child will be deletnd and parent->left becomes null
							delete child;
							parent->setLeft(NULL);
						}
						else { // child will be deletnd and parent->right becomes null
							delete child;
							parent->setRight(NULL);
						}
						second = false;
					}
				}
				left = true;
			}
		}
		std::cout << "Done" << std::endl;
	}
};