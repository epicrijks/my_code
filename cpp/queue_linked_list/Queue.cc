#include <iostream>
#include "Queue.h"

namespace jw {

// Dtor - delete all remaining nodes
template <typename T>
jw::Queue<T>::~Queue() {
  QueueNode<T>* temp = _head;
  while (_head != nullptr) {
    temp = _head;
    _head = _head->getNext();
    delete temp;
  }
}

// Add a value to the back of the queue
template <typename T>
void jw::Queue<T>::enqueue(const T& value) {
  if (_head == nullptr) {
    _head = new QueueNode<T>(value);
    _tail = _head;
  } else {
    _tail->setNext(new QueueNode<T>(value));
    _tail = _tail->getNext();
  }
}

// Return value at front of queue and remove from queue
template <typename T>
const T jw::Queue<T>::dequeue() {
  if (this->isEmpty()) {
    std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
    exit(EXIT_FAILURE);
  }

  T queueValue = _head->getValue();

  if (_head == _tail) {
    _tail = nullptr;
  }

  QueueNode<T>* temp = _head;
  _head = _head->getNext();
  delete temp;

  return queueValue;
}

// Returns true if Queue is empty, otherwise False
template <typename T>
bool jw::Queue<T>::isEmpty() const {
  return _head == nullptr;
}

// Print Queue as Linked List for debugging
template <typename T>
void jw::Queue<T>::printDebug() const {
  QueueNode<T>* ptr = _head;
  while (ptr != nullptr) {
    std::cout << ptr->getValue() << " -> "; 
    ptr = ptr->getNext();
  }
  std::cout << std::endl;
}


}