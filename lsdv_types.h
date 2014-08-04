#ifndef __H_LSDV_TYPES_
#define __H_LSDV_TYPES_

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
struct Link {
  T ett;
  unsigned chnl;
};

template<class T>
class Path {
 public:
 Path(): capacity(0), size(0) {
//    p = NULL;
    //    capacity = 0;
    //    size = 0;
  }

 Path(unsigned capacity): capacity(capacity), size(0) {//cout << "before: " << p << endl;
//        p = (struct Link *) malloc(capacity * sizeof(struct Link));
//    p = new Link[3];//cout << "after: " << p << endl;
    //    size = 0;
  }

  Path(const Path &path) {
    //    p = (Link<T> *) malloc (capacity * sizeof(Lint<T>));
//    p = new Link[path.capacity];
    capacity = path.capacity;
    size = path.size;
    if (p != NULL) {
      for (int i = 0; i < size; ++i) {
	//	memcpy(&p[i], &path.p[i], sizeof(p[i]));
	p[i] = path.p[i];/*
			   p[i].ett = path.p[i].ett;
			   p[i].chnl = path.p[i].chnl;*/
      }
    }
  }

  ~Path() {
    //    capacity = 0;
    //    size = 0;
    //    free(p);
//    delete []p;
  }
  
  unsigned size() const {
    return size;
  }

  unsigned capacity() const {
    return capacity;
  }

  bool empty() const {
    return (size == 0) ? true : false;
  }
  /*  
#if 0
  void resize(unsigned newCapacity = 0) const {
    if (newCapacity == 0) {
      newCapacity = 2 * capacity;
    }
    assert(newCapacity >= capacity);
    Link *newPath = new Link[newCapacity];
    for (unsigned i = 0; i < capacity; ++i) {
      newPath[i].ett = p[i].ett;
      newPath[i].chnl = p[i].chnl;
    }
    //    free(p);
//    delete []p;
//    p = newPath;
    newPath = NULL;
  }
#endif
  */
  Link<T> at(const int i) {
    assert(i >= 0 && i < size);
    return this->p[i];
  }

  inline Link<T> &operator [] (const int i) {
    //    static Link<T> link;
    assert(i >= 0 && i < size);//assert(i < capacity);
    //    if (i < size) {
      return this->p[i];
      /*    }
    else if (i >= capacity) {
//      resize();
    }
    return link;*/
  }
  
  const Link<T> &operator [] (const int i) const {
    //    static Link<T> link;
    assert(i >= 0 && i < size);
    //    if (i < size) {
      return this->p[i];
      /*    }
    else if (i >= capacity) {
      //resize();
    }
    return link;*/
  }

  Link<T> front() {
    return this->p[0];
  }

  const Link<T> front() const {
    return this->p[0];
  }

  Link<T> back() {
    return this->p[size - 1];
  }

  const Link<T> back() const {
    return this->p[size - 1];
  }

  void push_back(const Link<T> link) {
    assert(size < capacity);
    //    if (size > capacity) {
      //      resize();
    //    }
    if (p+size != NULL) {
      //      memcpy(p+size, &link, sizeof(link));
      p[size].ett = link.ett;
      p[size].chnl = link.chnl;
      ++size;
    }
  }

  void pop_back() {
    --size;
    assert(size >= 0);
    return;
  }

  friend Path & operator + (const Path<T> p1, const Path<T> p2) {
    unsigned capacity = p1.capacity() + p2.capacity();
    Path<T> res(capacity);
    for (unsigned i = 0; i < p1.size(); ++i) {
      res.push_back(p1[i]);
    }
    for (unsigned i = 0; i < p2.size(); ++i) {
      res.push_back(p2[i]);
    }
    return res;
  }

  Path & operator = (const Path<T> p2) {
    capacity = p2.capacity();
    size = p2.size();
    Path<T> res(capacity);
    for (unsigned i = 0; i < size; ++i) {
      res.push_back(p2[i]);
    }

    return res;
  }

  void initialize() {//            srand((unsigned)time(NULL));
    for (int i = 0; i < capacity; ++i) {
      Link<T> link;// = createLink();
      __ESBMC_assume(0 < link.ett && link.ett < 100 && link.chnl < 3);
      //      link.ett = rand()%100;//cout << link.ett << endl;
      //      link.chnl = rand()%3;//cout << link.chnl << endl;      cout << p+size << endl;
      push_back(link);
      //      cout << capacity << size << endl;
      //cout << p+size << endl;
      /*	       p[i].ett = link.ett;
		       p[i].chnl = link.chnl;
		       ++size;*/
    }
  }

 private:
  mutable Link<T> p[30];
  unsigned capacity;
  unsigned size;
};

#endif // __H_LSDV_TYPES_
