#ifndef __H_HOP_CNT_
#define __H_HOP_CNT_

#include "lsdv_types.h"

template<class T>
int weight(const Path<T> &path) {
  return path.size();
}

#endif // __H_HOP_CNT_
