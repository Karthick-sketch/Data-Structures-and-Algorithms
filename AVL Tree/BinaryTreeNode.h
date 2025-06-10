class BinaryTreeNode {
  int data;
  BinaryTreeNode *left, *right;

  public:

  BinaryTreeNode(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }

  void setData(int data) {
    this->data = data;
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
