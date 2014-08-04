#ifndef __H_GEOGR_TYPES_
#define __H_GEOGR_TYPES_

#include <cassert>
/*
template <class T>
class Node {
 public:
 Node() {}

 Node(const T &x, const T &y): x(x), y(y) {}

 Node(const Node &node): x(node.x), y(node.y) {}

  ~Node() {}

  void setX(const T &x) {
    this->x = x;
  }

  T getX() const {
    return x;
  }

  void setY(const T &y) {
    this->y = y;
  }

  T getY() const {
    return y;
  }

  Node & operator = (const Node<T> &node) {
    this->x = node.x;
    this->y = node.y;

    return *this;
  }

 private:
  T x;
  T y;
};
*/

template <class T>
struct Node {
  T x;
  T y;
};

template <class T>
class Link {
 public:
 Link() {
    Node<T> start, end;
    this->start = start;
    this->end = end;
  }
 /*
 Link(const T &start_x, const T &start_y, const T &end_x, const T &end_y):
 start(start_x, start_y), end(end_x, end_y) {}
 */
 Link(const Node<T> start, const Node<T> end): start(start), end(end) {}

 Link(const Link &link): start(link.start), end(link.end) {}

  ~Link() {}

  void setStart(const Node<T> start) {
    this->start = start;
  }

  Node<T> getStart() const {
    return start;
  }

  void setEnd(const Node<T> end) {
    this->end = end;
  }

  Node<T> getEnd() const {
    return end;
  }

  void setSrc(const Node<T> src) {
    this->src = src;
  }

  Node<T> getSrc() const {
    return src;
  }

  static Node<T> getDest() {
    return dest;
  }
  
  Link<T> reverseLink() {
    Link<T> res(end, start);
    return res;
  }
  
  virtual void printLink() {
    std::cout << "(" << start.x << "," << start.y << ")"
	      << "->" << "(" << end.x << "," << end.y << ")" << std::endl;
  }

  static Node<T> dest;

 protected:
  Node<T> start;
  Node<T> end;
  Node<T> src;
};

#endif // __H_GEOGR_TYPES_
