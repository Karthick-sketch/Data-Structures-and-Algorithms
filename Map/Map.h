template <typename K, typename V>
class Map {
  MapNode<K, V> *head, *tail;

  void exitProgram(K key) {
		std::cout << "error: Unable to find the key '" << key << "'" << std::endl;
		clear();
    exit(0);
	}

public:
  Map() {
    this->head = NULL;
    this->tail = NULL;
  }

  int length() {
    int len = 0;
    MapNode<K, V> *ptr = head;
    while (ptr != NULL) {
      ptr = ptr->getNext();
      len++;
    }
    return len;
  }

  V operator [] (K key) {
    return get(key);
  }

  void set(K key, V value) {
    MapNode<K, V> *ptr = head;
    // replace the value if the key is exists
    while (ptr != NULL) {
      if (ptr->getKey() == key) {
        ptr->setValue(value);
        break;
      }
      ptr = ptr->getNext();
    }
    // store the value if the key is not exists
    if (ptr == NULL) {
      MapNode<K, V> *node = new MapNode<K, V>(key, value);
      if (head == NULL) {
        head = node;
      } else {
        tail->setNext(node);
      }
      tail = node;
    }
  }

  V get(K key) {
    V value;
    MapNode<K, V> *ptr = head;
    while (ptr != NULL) {
      if (ptr->getKey() == key) {
        value = ptr->getValue();
        break;
      }
      ptr = ptr->getNext();
    }
    if (ptr == NULL) {
      exitProgram(key);
    }
    return value;
  }

  // return all keys as an array
  K[] getKeys() {
    K keys[length()];
    MapNode<K, V> *ptr = head;
    for (int i = 0; i < length(); i++) {
      keys[i] = ptr->getKey();
      ptr = ptr->getNext();
    }
    return keys;
  }

  // return all values as a LinkedList
  V[] getValues() {
    V values[length()];
    MapNode<K, V> *ptr = head;
    for (int i = 0; i < length(); i++) {
      values[i] = ptr->getValue();
      ptr = ptr->getNext();
    }
    return values;
  }

  // delete all existing nodes
	void clear() {
		if (head != NULL) {
			MapNode<K, V> *ptr = NULL;
			while (head != NULL) {
				ptr = head;
				head = head->getNext();
				delete ptr;
			}
			head = tail = NULL;
		}
	}

	// delete all existing nodes when exiting the program
	~Map() {
    clear();
  }
};
