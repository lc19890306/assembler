#ifndef __H_GEOGR_FUNCTIONS_
#define __H_GEOGR_FUNCTIONS_

#include "adv_greedy_forwarding_v1.h"
#include <cassert>

void initialize() {
  Node<int> dest;

  //  GFLink<T>::src = src;
  GFLink<T>::dest = dest;
}

GFLink<T> createLink() {
  Node<int> start, end, src;
  GFLink<T> res(start, end);
  res.setSrc(src);
  //  res.start = start;
  //  res.end = end;

  return res;
}

GFLink<T> createLink(Node<int> start) {
  Node<int> end, src;
  GFLink<T> res(start, end);
  res.setSrc(src);

  return res;
}

GFLink<T> createLink(Node<int> start, Node<int> end) {
  Node<int> src;
  GFLink<T> res(start, end);
  res.setSrc(src);

  return res;
}

GFLink<T> reverseLink(GFLink<T> l) {
  Node<int> start = l.getEnd();
  Node<int> end = l.getStart();
  Node<int> src = l.getSrc();
  GFLink<T> res(start, end);
  res.setSrc(src);
  //  res.start = l.end;
  //  res.end = l.start;

  return res;
}

GFLink<T> *createPath(unsigned num) {
  GFLink<T> *res;
  assert(num > 0);
  res[0] = createLink();
  for (int i = 1; i < num; ++i) {
    Node<int> node;
    res[i] = createLink(res[i-1].getEnd(), node);
  }

  return res;
}

#endif // __H_GEOGR_FUNCTIONS_
