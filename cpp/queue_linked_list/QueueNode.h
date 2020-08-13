#ifndef QUEUE_NODE_H_
#define QUEUE_NODE_H_

namespace jw {

template <typename T>
class QueueNode {
 public:
  QueueNode(const T& value) : _value(value), _next(nullptr) {}
  QueueNode(const T& value, const QueueNode& next) : _value(value), _next(next) {}
  ~QueueNode() {}
  QueueNode(const QueueNode&) = delete;
  QueueNode &operator=(const QueueNode&) = default;

  const T& getValue() const { return _value; }
  QueueNode<T>* getNext() const { return _next; }
  void setValue(const T& value) { _value = value; }
  void setNext(QueueNode<T>* next) { _next = next; }

 private:
  T _value;
  QueueNode<T>* _next;
};

}

#endif