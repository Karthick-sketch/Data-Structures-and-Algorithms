#include <math.h>

int jumpSearch(int array[], int size, int search) {
  int jump = int(sqrt(size));
  int prev = 0, next = 0;
  while (prev < size) {
    next = min(next + jump, size - 1);
    if (search <= array[next]) {
      for (; prev <= next; prev++) {
        if (array[prev] == search) {
          return prev;
        }
      }
      break;
    }
    prev = next + 1;
  }
  return -1;
}
