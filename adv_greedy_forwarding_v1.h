#ifndef __H_ADV_GREEDY_FORWARDING_V1_
#define __H_ADV_GREEDY_FORWARDING_V1_

#include "cmath"
#include "geogr_types.h"

template<class T>
class GFLink : public Link<T> {
 public:
 GFLink(): Link<T>() {
    //    assert(quality > 0);
  }
  /*
 GFLink(const T &start_x, const T &start_y, const T &end_x, const T &end_y, const T &quality):
  Link<T>(start_x, start_y, end_x, end_y), quality(quality) {
    assert(quality > 0);
  }
  */
 GFLink(const Node<T> start, const Node<T> end):
  Link<T>(start, end) {
    //    assert(quality > 0);
  }
  
 GFLink(const Node<T> start, const Node<T> end, const T quality):
  Link<T>(start, end), quality(quality) {
    //    assert(quality > 0);
  }
  
 GFLink(const GFLink &link): quality(link.quality) {
    //    assert(quality > 0);
  }
  
  ~GFLink() {}

  void setQuality(const T quality) {
    assert(quality > 0);
    this->quality = quality;
  }

  T getQuality() const {
    return quality;
  }
  /*
  GFLink & operator = (const GFLink<T> l) {
    this->start = l.start;
    this->end = l.end;
    this->quality = l.quality;

    return *this;
  }
  */
  GFLink<T> reverseLink() {
    GFLink<T> res(end, start);
    assert(quality > 0);
    res.setQuality(quality);
    return res;
  }
    
  virtual void printLink() {
    std::cout << "(" << this->start.x << "," << this->start.y << ")"
	      << "->" << "(" << this->end.x << "," << this->end.y << ")" ":" << quality << std::endl;
  }

 protected:
  T quality;
};

template<class T>
float dist(const Node<T> u, const Node<T> d) {
  float res = (u.x - d.x) * (u.x - d.x) + (u.y - d.y) * (u.y - d.y);
  __ESBMC_assume(res > 0);
  float ret = sqrt(res);//CarmSqrt(res);
  __ESBMC_assume(ret > 0);

  return ret;
}

template<class T>
float weight(const GFLink<T> l) {
  Node<T> d = l.getDest();
  Node<T> u = l.getStart();
  Node<T> v = l.getEnd();
  T quality = l.getQuality();
  float dist_ud = dist(u, d);
  assert(dist_ud != 0);
  float dist_vd = dist(v, d);
  assert(dist_vd != 0);
  float res = dist_ud - dist_vd + quality;
 
  return res;
}

#endif // __H_ADV_GREEDY_FORWARDING_V1_
