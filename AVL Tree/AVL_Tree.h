class AVLTree {
	Node* root;

	void display(Node* temp) {
		if (temp->getLeft() != NULL)
			display(temp->getLeft());
		std::cout << temp->getData() << ", ";
		if (temp->getRight() != NULL)
			display(temp->getRight());
	}

	public:

	AVLTree() {	root = NULL;	}

	int findBalanceFactor(Node* temp) {
		if (temp->getLeft() == NULL && temp->getRight() == NULL)
			return 0;
		else {
			Node* tmp = temp->getLeft();
			int left = 0, right = 0;
			for (int i = 0;i < 2;i++) {
				int l = 0, r = 0;

				if (tmp != NULL && findBalanceFactor(tmp) >= 0) {
					while (tmp != NULL) {
						tmp = (tmp->getLeft() != NULL) ? tmp->getLeft() : tmp->getRight();
						l++;
					}
				}
				else {
					while (tmp != NULL) {
						tmp = (tmp->getRight() != NULL) ? tmp->getRight() : tmp->getLeft();
						r++;
					}
				}
				if (i == 0) {
					left = l+r;
					tmp = temp->getRight();
				}
				else 	right = r+l;
			}
			return left-right;
		}
	}

	void selfBalancing(Node* child, Node* parent) {
		if (child->getLeft() != NULL)
			selfBalancing(child->getLeft(), child);
		if (child->getRight() != NULL)
			selfBalancing(child->getRight(), child);

		int ht = findBalanceFactor(child);
		Node *temp = NULL, *tmp = NULL;

		if (ht < -1) {
			temp = child->getRight();
			if (findBalanceFactor(temp) == 1) {	// RL Rotation
				tmp = temp->getLeft();
				Node* tmp2 = tmp->getRight();
				tmp->setRight(temp);
				temp->setLeft(tmp2);
				child->setRight(tmp);

				temp = tmp;
			}
			// RR Rotation
			tmp = temp->getLeft();
			temp->setLeft(child);
			child->setRight(tmp);
		}
		else if (ht > 1) {
			temp = child->getLeft();
			if (findBalanceFactor(temp) == -1) {	// LR Rotation
				Node* tmp = temp->getRight();
				Node* tmp2 = tmp->getLeft();
				tmp->setLeft(temp);
				temp->setRight(tmp2);
				child->setLeft(tmp);

				temp = tmp;
			}
			// LL Rotation
			tmp = temp->getRight();
			temp->setRight(child);
			child->setLeft(tmp);
		}
		if (ht < -1 || ht > 1) {
			if (child == root)	root = temp;
			else if (parent->getLeft() == child)	parent->setLeft(temp);
			else	parent->setRight(temp);
		}
	}

	void insert(int val) {
		if (search(val) == NULL) {
			Node* node = new Node(val);
			if (root == NULL)	root = node;
			else {
				Node* temp = root;
				while (true) {
					if (val < temp->getData()) {
						if (temp->getLeft() == NULL) {
							temp->setLeft(node);
							break;
						}
						else	temp = temp->getLeft();
					}
					else {
						if (temp->getRight() == NULL) {
							temp->setRight(node);
							break;
						}
						else	temp = temp->getRight();
					}
				}
			}
			selfBalancing(root, root);
		}
	}

	Node* search(int val, bool showItr = false) {
		Node *temp = root, *address = NULL; // if user input is not in the true it returns NULL
		bool isThere = true;
		int itr = 0;

		if (temp != NULL) {
			while (isThere) {
				if (temp != NULL && temp->getData() == val) { // if user input is equal to tmp.data temp's address assignnd to variable called address
					isThere = false;
					address = temp;
				}
				else if (val < temp->getData()) {
					if (temp->getLeft() == NULL)	isThere = false;
					else	temp = temp->getLeft();
				}
				else {
					if (temp->getRight() == NULL)	isThere = false;
					else	temp = temp->getRight();
				}
				itr++;
			}
		}
		if (showItr)	std::cout << "Number of iterations: " << itr << std::endl;

		return address;
	}

	int maximum() { // in this function temp goes to last left child in the tree, then it returns the minimum value
		Node* temp = root;
		bool run = true;
		while (run) {
			if (temp->getRight() == NULL)	run = false;
			else	temp = temp->getRight();
		}
		return temp->getData();
	}

	int minimum() { // in this function temp goes to last right child in the tree, then it returns the maximum value
		Node* temp = root;
		bool run = true;
		while (run) {
			if (temp->getLeft() == NULL)	run = false;
			else	temp = temp->getLeft();
		}
		return temp->getData();
	}

	void display() {
		if (root != NULL) {
			std::cout << '[';
			display(root);
			std::cout << "\b\b]" << std::endl;
		}
		else	std::cout << "[]" << std::endl;
	}

	void Delete(int val) {
		Node *child = root, *parent = NULL;
		bool exists = true;
		while (exists) {
			if (val == child->getData()) {
				if (child->getLeft() != NULL) {
					Node *temp1 = child->getLeft(), *temp2 = temp1;
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
								selfBalancing(root, root);	break;
							}
							else {
								parent->setRight(temp1);
								delete child;	selfBalancing(root, root);
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
				else if (child == root) {
					root = NULL;
					delete child;
				}
				else {
					(parent->getRight() == child) ? parent->setRight(NULL) : parent->setLeft(NULL);
					delete child;
				}
				std::cout << val << " is deleted" << std::endl;
				exists = false;	selfBalancing(root, root);
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

	~AVLTree() {
		if (root != NULL) {
			Node* child;
			Node* parent;
			bool left = true;
			bool first = true;
			bool second = false;

			while (first) {
				child = root;
				parent = NULL;
				if (root->getLeft() == NULL && root->getRight() == NULL) {
					delete root;	// if root's all children are null, root will be deleted
					first = false;
				}
				else	second = true;

				while(second) {
					if (child->getLeft() == NULL)
						left = false; // left is false, then child goes to right
					else {
						parent = child;
						child = child->getLeft();
					}

					if (!left) {
						if (child->getRight() == NULL)
							left = true; // if child->right is not exists left will become true, because we have to check next set nodes
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