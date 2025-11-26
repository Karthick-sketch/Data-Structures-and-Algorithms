template <typename K, typename V>
class MapNode {
private:
  K key;
  V value;
  MapNode* next;

public:
  MapNode(K key, V value) {
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

  void setNext(MapNode* next) {
    this->next = next;
  }

  MapNode* getNext() {
    return next;
  }
};
