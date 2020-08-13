#ifndef QUEUE_H_
#define QUEUE_H_

namespace jw {

template <typename T>
class Queue {
 public:
  explicit Queue(int capacity) : _data((capacity > 0) ? new T[capacity] : new T[16]), 
                                 _capacity((capacity > 0) ? capacity : 16), 
                                 _currentSize(0),
                                 _front(0),
                                 _back(0) {}
  ~Queue() { delete _data; }

  bool enqueue(const T&);
  bool dequeue(T&);
  bool isEmpty() const;
  bool isFull() const;

  void printDebug() const;

 private:
  T* _data;
  int _capacity;
  int _currentSize;
  int _front;
  int _back;

  void _moveItNext(int&) const;
};

}

#endif