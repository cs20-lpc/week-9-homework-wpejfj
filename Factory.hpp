#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

template<typename T>
class Factory {
public:
  static Queue<T> *GetQueue(int length = -1) {
    if (length == -1) {
      return new LinkedQueue<T>();
    }
    else {
      return new ArrayQueue<T>(length);
    }
  }
};

#endif
