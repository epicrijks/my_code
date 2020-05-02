#ifndef MY_CODE_CPP_S_LINKED_LIST_H_
#define MY_CODE_CPP_S_LINKED_LIST_H_

namespace jw {

template <class T>
class SLinkedList {
  struct SListNode {
    T value;
    SListNode* next;

    SListNode(T value, SListNode* next = nullptr) : value(value), next(next) {}
  };

 public:
  explicit SLinkedList() : head(nullptr) {}
  ~SLinkedList();
  SLinkedList(const SLinkedList&) =delete;
  SLinkedList &operator=(const SLinkedList&) =delete;
  
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
  SListNode* head;
};

}

#endif