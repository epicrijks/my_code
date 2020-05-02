#ifndef MY_CODE_CPP_D_LINKED_LIST_H_
#define MY_CODE_CPP_D_LINKED_LIST_H_

namespace jw {

template <class T>
class DLinkedList {
  struct DListNode {
    T value;
    DListNode* next;
    DListNode* prev;

    DListNode(T newValue, DListNode* nextNode = nullptr, 
                          DListNode* prevNode = nullptr) {
      value = newValue;
      next = nextNode;
      prev = prevNode;
    }
  };

 public:
  explicit DLinkedList() : head(nullptr), tail(nullptr) {}
  ~DLinkedList();
  DLinkedList(const DLinkedList&) =delete;
  DLinkedList &operator=(const DLinkedList&) =delete;
  
  int size() const;

  bool empty() const;

  const T &value_at(int index) const;
  const T &front() const;
  const T &back() const;
  const T &value_from_back(int n) const;
  T pop_front();
  T pop_back();

  void push_front(T value);
  void push_back(T value);
  void insert(int index, T value);
  void erase(int index);
  void reverse();
  void remove_value(T value);

  void debug() const;

  // Exception Classes
  class OutOfBounds {};
  class MemAllocError {};

 private:
  DListNode* head;
  DListNode* tail;
};

}

#endif