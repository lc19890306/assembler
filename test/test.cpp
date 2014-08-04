#include <iostream>

using namespace std;

struct S {
  int x;
  int y;
};

class C {
public:
  C (): _capacity(0), _size(0) {
    a = NULL;
  }

  C(int capacity): _capacity(capacity), _size(0) {
    a = new S[_capacity];/*
    for (int i = 0; i < _capacity; ++i) {
      S s;
      a[i].
      }*/
  }

  C(const C &c) {
    a = new S[c._capacity];
    _capacity = c._capacity;
    _size = c._size;
    if (a != NULL) {
      for (int i = 0; i < _size; ++i) {
	a[i] = c.a[i];
      }
    }
  }

  ~C() {
    delete []a;
  }

  void initialize() {
    for (int i = 0; i < _capacity; ++i) {
      S s;
      a[i].x = s.x;
      a[i].y = s.y;
      ++_size;
    }
  }

private:
  S *a;
  int _capacity;
  int _size;
};

int main() {
  C a(3), b(3), c(3);

  a.initialize();
  b.initialize();
  c.initialize();

  return 0;
}
