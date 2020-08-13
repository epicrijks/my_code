#include <iostream>
#include "QueueNode.h"

#ifndef QUEUE_H_
#define QUEUE_H_

namespace jw {

template <typename T>
class Queue {
 public:
  explicit Queue() : _head(nullptr), _tail(nullptr) {}
  ~Queue();
  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;

  void enqueue(const T&);
  const T dequeue();
  bool isEmpty() const;

  void printDebug() const;

 private:
   QueueNode<T>* _head;
   QueueNode<T>* _tail;
};

}

#endif