class AVLTree : public BinarySearchTree {
	public:

	AVLTree() { root = NULL; }

	int findBalanceFactor(TreeNode* temp) {
		if (temp->getLeft() == NULL && temp->getRight() == NULL)
			return 0;
		else {
			TreeNode* tmp = temp->getLeft();
			int left = 0, right = 0;
			for (int i = 0;i < 2;i++) {
				int num = 0;

				if (tmp != NULL && findBalanceFactor(tmp) >= 0) {
					for (;tmp != NULL;num++) {
						tmp = (tmp->getLeft() != NULL) ? tmp->getLeft() : tmp->getRight();
					}
				} else {
					for (;tmp != NULL;num++) {
						tmp = (tmp->getRight() != NULL) ? tmp->getRight() : tmp->getLeft();
					}
				}

				if (i == 0) {
					left = num;
					tmp = temp->getRight();
				} else right = num;
			}

			return left-right;
		}
	}

	void selfBalancing(TreeNode* child, TreeNode* parent) {
		if (child->getLeft() != NULL)
			selfBalancing(child->getLeft(), child);
		if (child->getRight() != NULL)
			selfBalancing(child->getRight(), child);

		int ht = findBalanceFactor(child);
		TreeNode *temp = NULL, *tmp1 = NULL, *tmp2 = NULL;

		if (ht < -1) {
			temp = child->getRight();
			if (findBalanceFactor(temp) == 1) {
				tmp1 = temp->getLeft();
				tmp2 = tmp1->getRight();
				// RL Rotation
				tmp1->setRight(temp);
				temp->setLeft(tmp2);
				child->setRight(tmp1);

				temp = tmp1;
			}
			// RR Rotation
			tmp1 = temp->getLeft();
			temp->setLeft(child);
			child->setRight(tmp1);
		} else if (ht > 1) {
			temp = child->getLeft();
			if (findBalanceFactor(temp) == -1) {
				tmp1 = temp->getRight();
				tmp2 = tmp1->getLeft();
				// LR Rotation
				tmp1->setLeft(temp);
				temp->setRight(tmp2);
				child->setLeft(tmp1);

				temp = tmp1;
			}
			// LL Rotation
			tmp1 = temp->getRight();
			temp->setRight(child);
			child->setLeft(tmp1);
		}

		if (ht < -1 || ht > 1) {
			if (child == root) root = temp;
			else if (parent->getLeft() == child) parent->setLeft(temp);
			else parent->setRight(temp);
		}
	}

	bool add(int val) {
		bool exists = BinarySearchTree::add(val);
		if (exists) selfBalancing(root, root);
		return exists;
	}

	bool remove(int val) {
		bool exists = BinarySearchTree::remove(val);
		if (exists) selfBalancing(root, root);
		return exists;
	}
};
