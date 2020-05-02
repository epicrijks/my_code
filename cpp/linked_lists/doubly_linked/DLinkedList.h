#ifndef MY_CODE_CPP_D_LINKED_LIST_H_
#define MY_CODE_CPP_D_LINKED_LIST_H_

#include <iostream>

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

// Deconstructor
template <class T>
DLinkedList<T>::~DLinkedList() {
  if (empty()) return;
  
  DListNode* ptr = head;
  DListNode* garbage = nullptr;

  while (ptr) {
    garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Returns number of elements in list
template <class T>
int DLinkedList<T>::size() const {
  int size = 0;
  if (empty()) return size;
  DListNode* ptr = head;

  while (ptr) {
    size++;
    ptr = ptr->next;
  }
  return size;
}

// Returns true if list contains at least one element; otherwise, false
template <class T>
bool DLinkedList<T>::empty() const {
  return (!head) ? true : false; 
}

// Returns the value stored at index
template <class T>
const T &DLinkedList<T>::value_at(int index) const {
  if(empty() || index < 0) throw OutOfBounds();
  DListNode* ptr = head;
  int currentNode = 0;
  
  while (ptr) {
    if (currentNode == index) {
      return ptr->value;
    }
    ptr = ptr->next;
  }
  throw OutOfBounds();
}

// Returns value from front of list -- does not pop
template <class T>
const T &DLinkedList<T>::front() const {
  if(empty()) throw OutOfBounds();
  return head->value;
}

// Returns value from front of list -- does not pop
template <class T>
const T &DLinkedList<T>::back() const {
  if(empty()) throw OutOfBounds();
  return tail->value;
}

// Returns nth value from back of list
template <class T>
const T &DLinkedList<T>::value_from_back(int n) const {
  if(empty() || n < 0) throw OutOfBounds();
  DListNode* ptr = tail;
  int currentNode = 0;
  
  while (ptr) {
    if (currentNode == n) {
      return ptr->value;
    }
    ptr = ptr->prev;
  }
  throw OutOfBounds();
}

// Removes and returns first value in list
template <class T>
T DLinkedList<T>::pop_front() {
  if(empty()) throw OutOfBounds();
  T returnVal = head->value;
  erase(0);
  return returnVal;
}

template <class T>
T DLinkedList<T>::pop_back() {
  if(empty()) throw OutOfBounds();
  DListNode* rear = tail;
  auto returnVal = tail->value;
  tail = tail->prev;
  tail->next = nullptr;
  delete rear;
  return returnVal;
}

// Inserts value into front of list
template <class T>
void DLinkedList<T>::push_front(T value) {
  insert(0, value);
}

// Inserts value into back of list
template <class T>
void DLinkedList<T>::push_back(T value) {
  if(empty()) {
    insert(0, value);
    return;
  }
  
  try {
    tail->next = new DListNode(value, nullptr, tail);
    tail = tail->next;
  } catch (std::bad_alloc) {
    throw MemAllocError();
  }
}

// Inserts value at position index in list
template <class T>
void DLinkedList<T>::insert(int index, T value) {
  if (empty()) {
    try {
      head = new DListNode(value, nullptr, nullptr);
      tail = head;
    } catch (std::bad_alloc) {
      throw MemAllocError();
    }
    return;
  }

  int currentNode = 0;
  DListNode* first = head->next;
  DListNode* second = head;

  if (index == currentNode) {
    try {
      head = new DListNode(value, second, nullptr);
      second->prev = head;
    } catch (std::bad_alloc) {
      throw MemAllocError();
    }
    return;
  }

  while (first) {
    ++currentNode;
    if (index == currentNode) {
      try {
        second->next = new DListNode(value, first, second);
      } catch (std::bad_alloc) {
      throw MemAllocError();
      }
    return;
    }
    second = first;
    first = first->next;
  }
  
  try {
    second->next = new DListNode(value, nullptr, second);
  } catch (std::bad_alloc) {
    throw MemAllocError();
  } 
}

// Erases value at index
template <class T>
void DLinkedList<T>::erase(int index) {
  if(empty() || index < 0) throw OutOfBounds();
  DListNode* first = head;
  int currentNode = 0;

  if (index == currentNode) {
    head = first->next;
    first->next->prev = nullptr;
    delete first;
    return;
  }

  while (first) {
    ++currentNode;
    if (index == currentNode) {
      first->prev->next = first->next;
      first->next->prev = first->prev;
      delete first;
      return;
    }
    first = first->next;
  }
  throw OutOfBounds();
}

// Reverses elements in list
template <class T>
void DLinkedList<T>::reverse() {
  // If list is empty or has one node, do nothing
  if (empty() || head == tail)
    return;

  // Swap head and tail
  DListNode* temp;
  temp = tail;
  tail = head;
  head = temp;

  DListNode* ptr = head;
  while (ptr) {
    temp = ptr->next;
    ptr->next = ptr->prev;
    ptr->prev = temp;
    ptr = ptr->next;
  }
}


// Removes first occurance of value from list
template <class T>
void DLinkedList<T>::remove_value(T value) {
  if (empty()) return;
  DListNode* ptr = head;

  if (ptr->value == value) {
    erase(0);
    return;
  }

  ptr = ptr->next;
  while (ptr) {
    if (ptr->value == value) {
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      delete ptr;
      return;
    }
    ptr = ptr->next;
  }
  return;
}

// Prints list contents for debugging
template <class T>
void DLinkedList<T>::debug() const {
  DListNode* ptr = head;

  while (ptr) {
    std::cout << ptr->value << " --> ";
    ptr = ptr->next;
  }
  std::cout << "nullptr\n";
}

}

#endif