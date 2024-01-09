class BinaryTreeNode {
	int data;
	BinaryTreeNode *left, *right;

	public:

	BinaryTreeNode(int val) {
		data = val;
		left = right = NULL;
	}

	void setData(int val) {
		data = val;
	}

	int getData() {
		return data;
	}

	void setLeft(BinaryTreeNode* link) {
		left = link;
	}

	BinaryTreeNode* getLeft() {
		return left;
	}

	void setRight(BinaryTreeNode* link) {
		right = link;
	}

	BinaryTreeNode* getRight() {
		return right;
	}
};
