#include <iostream>
#include <sstream>
#include "MapNode.h"
#include "Map.h"

using namespace std;

int main() {
  Map<string, string> map;
  map.set("name", "Thookudurai");
  map.set("age", "47");
  map.set("gender", "male");

  string keys[] = map.getKeys();
  for (int i = 0; i < map.length(); i++) {
    cout << keys[i] << " : " << map.get(keys[i]) << endl;
  }

  return 0;
}
