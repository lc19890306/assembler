#ifndef __H_WCETT_
#define __H_WCETT_

#include <iostream>
#include <cassert>
//#include <cstdlib>
//#include <stdlib.h>

using namespace std;

/*
class Link {
 public:
  Link() {}
  ~Link() {}
  int ett;
  unsigned chnl;
};
*/


struct Link {
  int ett;
  unsigned chnl;
};


class Path {
 public:
 Path(): _capacity(0), _size(0) {
    p = NULL;
  }

 Path(unsigned capacity): _capacity(capacity), _size(0) {
//    p = new Link[_capacity];
	p = (struct Link *)malloc(sizeof(struct Link)*_capacity);
  }

  Path(const Path &path) {
//    p = new Link[path._capacity];
	p = (struct Link *)malloc(sizeof(struct Link)*path._capacity);
    _capacity = path._capacity;
    _size = path._size;
    if (p != NULL) {
      for (int i = 0; i < _size; ++i) {
	p[i] = path.p[i];
      }
    }
  }

  ~Path() {
//    delete []p;
	free(p);
  }
  
  unsigned size() const {
    return _size;
  }

  unsigned capacity() const {
    return _capacity;
  }

  bool empty() const {
    return (_size == 0) ? true : false;
  }
  
  void resize(unsigned newCapacity = 0) const {
    if (newCapacity == 0) {
      newCapacity = 2 * _capacity;
    }
    assert(newCapacity >= _capacity);
//    Link *newPath = new Link[newCapacity];
    struct Link *newPath = (struct Link *)malloc(sizeof(struct Link)*newCapacity);
    for (unsigned i = 0; i < _capacity; ++i) {
      newPath[i].ett = p[i].ett;
      newPath[i].chnl = p[i].chnl;
    }

    delete []p;
    p = newPath;
    newPath = NULL;
  }

  Link at(int i) {
    assert(i >= 0 && i < _size);
    return this->p[i];
  }

  inline struct Link &operator [] (int i) {
    static struct Link link;
    assert(i >= 0);assert(i < _capacity);
    if (i < _size) {
      return this->p[i];
    }
    else if (i >= _capacity) {
      resize();
    }
    return link;
  }
  
  const struct Link &operator [] (int i) const {
    static struct Link link;
    assert(i >= 0);
    if (i < _size) {
      return this->p[i];
    }
    else if (i >= _capacity) {
      resize();
    }
    return link;
  }

  struct Link front() {
    return this->p[0];
  }

  const struct Link front() const {
    return this->p[0];
  }

  struct Link back() {
    return this->p[_size - 1];
  }

  const struct Link back() const {
    return this->p[_size - 1];
  }

  void push_back(const struct Link &link) {
    if (_size > _capacity) {
    }
    if (p+_size != NULL) {
      p[_size].ett = link.ett;
      p[_size].chnl = link.chnl;
      ++_size;
    }
  }

  void pop_back() {
    --_size;
    assert(_size >= 0);
    return;
  }

  friend Path operator + (const Path &p1, const Path &p2) {
    unsigned capacity = p1.capacity() + p2.capacity();
    Path res(capacity);
    for (unsigned i = 0; i < p1.size(); ++i) {
      res.push_back(p1[i]);
    }
    for (unsigned i = 0; i < p2.size(); ++i) {
      res.push_back(p2[i]);
    }
    return res;
  }
  /*
    Path<T> operator = (const Path<T> &p2) {
    _capacity = p2.capacity();
    _size = p2.size();
    Path<T> res(_capacity);
    for (unsigned i = 0; i < _size; ++i) {
    res.push_back(p2[i]);
    }

    return res;
    }
  */
  void initialize() {
    for (int i = 0; i < _capacity; ++i) {
      struct Link link;
      __ESBMC_assume(0 < link.ett && link.ett < 100 && link.chnl < 3);
      push_back(link);
    }
  }

 private:
  mutable struct Link *p;
  unsigned _capacity;
  unsigned _size;
};

#define MAX 3
#define beta 0.5

float weight(Path p) {
  int i;
  unsigned channel[MAX] = {0};
  float max = 0, res = 0;
  for (i = 0; i < MAX; ++i) {
    res += p[i].ett;
    __ESBMC_assume(p[i].chnl < MAX);
    ++channel[p[i].chnl];
  }
  for (i = 0; i < MAX; ++i) {
    if (channel[i] > max)
      max = channel[i];
  }
  res = (1 - beta) * res + beta * max;

  return res;
}

#endif // __H_WCETT_
