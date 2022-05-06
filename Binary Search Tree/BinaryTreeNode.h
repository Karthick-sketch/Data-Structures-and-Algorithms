class TreeNode {
	int data; TreeNode *left, *right;

	public:

	TreeNode(int val) { data = val; left = NULL; right = NULL; }

	void setData(int val) { data = val; }
	int getData() { return data; }

	void setLeft(TreeNode* link) { left = link; }
	TreeNode* getLeft() { return left; }

	void setRight(TreeNode* link) { right = link; }
	TreeNode* getRight() { return right; }
};
