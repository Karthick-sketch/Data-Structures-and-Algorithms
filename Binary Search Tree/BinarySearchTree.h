class BinarySearchTree {
private:
    void print(BinaryTreeNode* temp) {
		if (temp->getLeft() != NULL) {
			print(temp->getLeft());
		}
		std::cout << temp->getData() << ' ';

		if (temp->getRight() != NULL) {
			print(temp->getRight());
		}
	}

	BinaryTreeNode* clear(BinaryTreeNode* temp) {
		if (temp->getLeft() != NULL) {
			temp->setLeft(clear(temp->getLeft()));
		}
		if (temp->getRight() != NULL) {
			temp->setRight(clear(temp->getRight()));
		}
		delete temp;
		return NULL;
	}

protected:
    BinaryTreeNode* root;

public:
    BinarySearchTree() {
		root = NULL;
	}

    bool add(int val) {
        bool exists = !search(val);
		if (exists) {
			BinaryTreeNode* node = new BinaryTreeNode(val);
			if (root == NULL) {
				root = node;
			} else {
				BinaryTreeNode* temp = root;
				while (true) {
					if (val < temp->getData()) {
						if (temp->getLeft() == NULL) {
							temp->setLeft(node);
							break;
						} else temp = temp->getLeft();
					} else {
						if (temp->getRight() == NULL) {
							temp->setRight(node);
							break;
						} else {
							temp = temp->getRight();
						}
					}
				}
			}
		}
        return exists;
	}

	bool search(int val) {
		BinaryTreeNode *temp = root;
		bool exists = false;

        while (temp != NULL && !exists) {
            if (temp->getData() == val) {
				exists = true;
			} else if (val < temp->getData()) {
				temp = temp->getLeft();
			} else {
				temp = temp->getRight();
			}
        }
		return exists;
	}

    // in this function temp goes to last left child in the tree, then it returns the value
	int maximum() {
		BinaryTreeNode* temp = root;
		while (temp->getRight() != NULL) {
			temp = temp->getRight();
		}
		return temp->getData();
	}

    // in this function temp goes to last right child in the tree, then it returns the value
	int minimum() {
		BinaryTreeNode* temp = root;
		while (temp->getLeft() != NULL) {
			temp = temp->getLeft();
		}
		return temp->getData();
	}

	// remove value from a tree
	bool remove(int val) {
		BinaryTreeNode *child = root, *parent = NULL;
		bool exists = search(val);

		while (exists) {
			if (child->getData() == val) {
				if (child->getLeft() != NULL && child->getRight() != NULL) {
					BinaryTreeNode* left = child->getLeft();
					BinaryTreeNode* right = child->getRight();

					if (child == root) {
						root = right;
					} else if (parent->getLeft() == child) {
						parent->setLeft(right);
					} else {
						parent->setRight(right);
					}

					while (right->getLeft() != NULL) {
						right = right->getLeft();
					}
					right->setLeft(left);
				} else {
					BinaryTreeNode* setBinaryTreeNode = (child->getLeft() != NULL) ? child->getLeft() : child->getRight();
					if (child == root) {
						root = setBinaryTreeNode;
					} else if (parent->getLeft() == child) {
						parent->setLeft(setBinaryTreeNode);
					} else {
						parent->setRight(setBinaryTreeNode);
					}
				}
				delete child;
				break;
			} else {
				parent = child;
				child = (val < child->getData()) ? child->getLeft() : child->getRight();
			}
		}
		return exists;
	}

	// print all values from a tree
	void print() {
        std::cout << "[ ";
		if (root != NULL) {
			print(root);
		}
        std::cout << "]" << std::endl;
	}

	// clear all values from a tree
	void clear() {
		if (root != NULL) {
			root = clear(root);
		}
	}

	~BinarySearchTree() {
		clear();
	}
};
