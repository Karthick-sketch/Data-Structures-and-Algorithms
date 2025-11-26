class BinaryTreeNode {
  int value;
  BinaryTreeNode *left, *right;

public:
  BinaryTreeNode(int value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
  }

  int getValue() {
    return value;
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
