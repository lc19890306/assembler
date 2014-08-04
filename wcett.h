#ifndef __H_WCETT_
#define __H_WCETT_

#include "lsdv_types.h"

#define MAX 20
#define beta 0.5

template<class T>
float weight(const Path<T> p) {
  int i;
  unsigned channel[MAX] = {0}, max = 0;
  T res = 0;//cout<<"here\n";
  for (i = 0; i < p.size(); ++i) {
    res += p[i].ett;__ESBMC_assume(p[i].chnl < MAX);
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
