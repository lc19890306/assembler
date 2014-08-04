/* RPF - Random Progress Forwarding
 * a packet is forwarded to the neighbor that has the maximum positive projected progress /
 * on the straight line segment joining the forwarding node and the destination
 * It has local minumum-free property
 * lacks odd symmetry
 */

#ifndef __H_RPF_
#define __H_RPF_

#include "cmath"
#include "geogr_types.h"

//#define PHI 0

float dist(Node<int> u, Node<int> d) {
  float res = (u.x - d.x) * (u.x - d.x) + (u.y - d.y) * (u.y - d.y);
  __ESBMC_assume(res > 0);
  float ret = sqrt(res);//CarmSqrt(res);
  __ESBMC_assume(ret > 0);

  return ret;
}

float weight(Link<int> l) {
  Node<int> d = l.getDest();
  Node<int> u = l.getStart();
  Node<int> v = l.getEnd();
  int prod = (v.x - u.x) * (d.x - u.x) + (v.y - u.y) * (d.y - u.y);
  float dist_ud = dist(u, d);
  __ESBMC_assume(dist_ud != 0);
  __ESBMC_assume(u.x != d.x || u.y != d.y);
  float ret = -prod/dist_ud;
  return ret;
}

#endif // __H_RPF_
