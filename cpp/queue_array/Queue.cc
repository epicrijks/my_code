#include <iostream>
#include "Queue.h"

namespace jw {

// Add value to back of queue if there is enough space
template <typename T>
bool jw::Queue<T>::enqueue(const T& value) {
  if (this->isFull()) {
    return false;
  }

  _data[_back] = value;
  _moveItNext(_back);
  _currentSize++;
  return true;
}

// If not empty, assigns front value to value, otherwise returns false
template <typename T>
bool jw::Queue<T>::dequeue(T& value) {
  if (this->isEmpty()) {
    return false;
  }

  value = _data[_front];
  _moveItNext(_front);
  _currentSize--;
  return true;
}

// Returns true is queue is full, otherwise false
template <typename T>
bool jw::Queue<T>::isFull() const {
  return _currentSize == _capacity;
}

// Returns true is queue is empty, otherwise false
template <typename T>
bool jw::Queue<T>::isEmpty() const {
  return _currentSize == 0;
}

// Print array contents for debugging purposes
template <typename T>
void jw::Queue<T>::printDebug() const {
  int ind = _front, 
      count = 0;
  while (count < _currentSize) {
    std::cout << _data[ind] << " -> ";
    _moveItNext(ind);
    count++;
  }
  std::cout << std::endl;
}

// Moves index ahead one, accounting for wrap-around
template <typename T>
void jw::Queue<T>::_moveItNext(int& index) const {
  index++;
  if (index == _capacity) {
    index = 0;
  }
}

}