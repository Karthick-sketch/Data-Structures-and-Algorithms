template <typename K, typename V>
class HashNode {
private:
  K key;
  V value;
  HashNode* next;

public:
  HashNode(K key, V value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
  }

  void setKey(K key) {
    this->key = key;
  }

  K getKey() {
    return key;
  }

  void setValue(V value) {
    this->value = value;
  }

  V getValue() {
    return value;
  }

  void setNext(HashNode* next) {
    this->next = next;
  }

  HashNode* getNext() {
    return next;
  }
};
