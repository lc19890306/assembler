#ifndef __H_LSDV_FUNCTIONS_
#define __H_LSDV_FUNCTIONS_

#include "RPF.h"
template<class T>
void createPath(Path<T> &path) {
  int capacity = path.capacity();
  unsigned size;
  __ESBMC_assume(0 < size && size <= capacity);
  for (int i = 0; i < size; ++i) {
    Link<T> link;
    __ESBMC_assume(0 < link.ett && link.ett < 100 && link.chnl < 3);
    path.push_back(link);
  }
}

#endif // __H_LSDV_FUNCTIONS_
