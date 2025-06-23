class BinarySearchTree {
private:
  void print(BinaryTreeNode* temp) {
    if (temp->getLeft() != NULL) {
      print(temp->getLeft());
    }
    std::cout << temp->getValue() << ' ';
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

  void insert(int value) {
    if (root == NULL) {
      root = new BinaryTreeNode(value);
    } else {
      BinaryTreeNode* node = root;
      while (true) {
        if (value < node->getValue()) {
          if (node->getLeft() == NULL) {
            node->setLeft(new BinaryTreeNode(value));
            break;
          }
          node = node->getLeft();
        } else if (value > node->getValue()) {
          if (node->getRight() == NULL) {
            node->setRight(new BinaryTreeNode(value));
            break;
          }
          node = node->getRight();
        } else {
          break;
        }
      }
    }
  }

  bool search(int value) {
    BinaryTreeNode *node = root;
    while (node != NULL) {
      if (value == node->getValue()) {
        return true;
      } else if (value < node->getValue()) {
        node = node->getLeft();
      } else {
        node = node->getRight();
      }
    }
    return false;
  }

  // in this function temp goes to last left child in the tree, then it returns the value
  int maximum() {
    BinaryTreeNode* temp = root;
    while (temp->getRight() != NULL) {
      temp = temp->getRight();
    }
    return temp->getValue();
  }

  // in this function temp goes to last right child in the tree, then it returns the value
  int minimum() {
    BinaryTreeNode* temp = root;
    while (temp->getLeft() != NULL) {
      temp = temp->getLeft();
    }
    return temp->getValue();
  }

  // remove value from a tree
  bool remove(int val) {
    BinaryTreeNode *child = root, *parent = NULL;
    bool exists = search(val);
    while (exists) {
      if (child->getValue() == val) {
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
        child = (val < child->getValue()) ? child->getLeft() : child->getRight();
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
