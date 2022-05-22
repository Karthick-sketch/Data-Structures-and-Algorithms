#include <iostream>
#include <sstream>
#include "List.h"
#include "Hash.h"

using namespace std;

int main() {
    Hash<string, string> hash;

    hash.set("name", "karthick");
    hash.set("age", "20");
    hash.set("gender", "male");

    List<string> keys = hash.getKeys();
    for (int i = 0;i < hash.length();i++) {
        cout << keys.get(i) << " : " << hash.get(keys.get(i)) << endl;
    }

    return 0;
}
