template <typename K, typename V>
class Hash {
    HashNode<K, V> *head, *tail;

    void exitProgram(K key) {
		std::cout << "error: Unable to find the key '" << key << "'" << std::endl;
		clear(); exit(0);
	}

    public:

    Hash() { head = tail = NULL; }

    int length() {
        int len = 0;
        HashNode<K, V> *ptr = head;
        while (ptr != NULL) {
            ptr = ptr->getLink();
            len++;
        }

        return len;
    }

    V operator [] (K key) { return get(key); }

    void set(K key, V value) {
        HashNode<K, V> *ptr = head;
        // replace the value if the key is exists
        while (ptr != NULL) {
            if (ptr->getKey() == key) {
                ptr->setValue(value);
                break;
            }
            ptr = ptr->getLink();
        }

        // store the value if the key is not exists
        if (ptr == NULL) {
            HashNode<K, V> *node = new HashNode<K, V>(key, value);
            if (head == NULL) head = node;
            else tail->setLink(node);
            tail = node;
        }
    }

    V get(K key) {
        V value;
        HashNode<K, V> *ptr = head;
        while (ptr != NULL) {
            if (ptr->getKey() == key) {
                value = ptr->getValue(); break;
            }
            ptr = ptr->getLink();
        }
        if (ptr == NULL) exitProgram(key);

        return value;
    }

    // return all keys as a list
    List<K> getKeys() {
        List<K> keys;
        HashNode<K, V> *ptr = head;
        while (ptr != NULL) {
            keys.push(ptr->getKey());
            ptr = ptr->getLink();
        }

        return keys;
    }

    // return all values as a list
    List<V> getValues() {
        List<V> values;
        HashNode<K, V> *ptr = head;
        while (ptr != NULL) {
            values.push(ptr->getValue());
            ptr = ptr->getLink();
        }

        return values;
    }

    // delete all existing nodes
	void clear() {
		if (head != NULL) {
			HashNode<K, V> *ptr = NULL;
			while (head != NULL) {
				ptr = head;
				head = head->getLink();
				delete ptr;
			}
			head = tail = NULL;
		}
	}

	// delete all existing nodes when exiting the program
	~Hash() { clear(); }
};
