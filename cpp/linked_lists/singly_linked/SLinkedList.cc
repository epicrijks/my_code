#include <new>  // bad_alloc
#include "SLinkedList.h"

namespace jw {

// Destructor
template <class T>
SLinkedList<T>::~SLinkedList() {
  if(empty()) return;
  SListNode* ptr = head;
  SListNode* garbage = nullptr;

  while (ptr) {
    garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Returns number of elements in list
template <class T>
int SLinkedList<T>::size() const {
  int size = 0;
  if (empty()) return size;
  SListNode* ptr = head;

  while (ptr) {
    size++;
    ptr = ptr->next;
  }
  return size;
}

// Returns true if list contains at least one element; otherwise, false
template <class T>
bool SLinkedList<T>::empty() const {
  if (!head)
    return true;
  else 
    return false;  
}

// Returns the value stored at index
template <class T>
const T &SLinkedList<T>::value_at(int index) const {
  if(empty() || index < 0) throw OutOfBounds();
  SListNode* ptr = head;
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
const T &SLinkedList<T>::front() const {
  if(empty()) throw OutOfBounds();
  return head->value;
}

// Returns last value in list
template <class T>
const T &SLinkedList<T>::back() const {
  if(empty()) throw OutOfBounds();
  SListNode* ptr = head;
  T returnVal;

  while (ptr) {
    returnVal = ptr->value;
    ptr = ptr->next;
  }

  return returnVal;
}

// Returns nth value from back of list
template <class T>
const T &SLinkedList<T>::value_from_back(int n) const {
  int back_ = size();
  --back_;

  return value_at(back_ - n);
}

// Removes and returns first value in list
template <class T>
T SLinkedList<T>::pop_front() {
  if(empty()) throw OutOfBounds();
  auto returnVal = head->value;
  erase(0);
  return returnVal;
}

// Removes and returns last value in list
template <class T>
T SLinkedList<T>::pop_back() {
  if(empty()) throw OutOfBounds();
  auto returnVal = back();
  erase(size()-1);
  return returnVal;
}

// Inserts value into front of list
template <class T>
void SLinkedList<T>::push_front(T value) {
  insert(0, value);
}

// Inserts value into back of list
template <class T>
void SLinkedList<T>::push_back(T value) {
  insert(size(), value);
}

// Inserts value at position index in list
template <class T>
void SLinkedList<T>::insert(int index, T value) {
  if (empty()) {
    try {
      head = new SListNode(value, nullptr);
    } catch (std::bad_alloc) {
      throw MemAllocError();
    }
    return;
  }

  int currentNode = 0;
  SListNode* first = head->next;
  SListNode* second = head;

  if (index == currentNode) {
    try {
      head = new SListNode(value, second);
    } catch (std::bad_alloc) {
      throw MemAllocError();
    }
    return;
  }

  while (first) {
    ++currentNode;
    if (index == currentNode) {
      try {
        second->next = new SListNode(value, first);
      } catch (std::bad_alloc) {
      throw MemAllocError();
      }
    return;
    }
    second = first;
    first = first->next;
  }
  
  try {
    second->next = new SListNode(value, nullptr);
  } catch (std::bad_alloc) {
    throw MemAllocError();
  } 
}

// Erases value at index
template <class T>
void SLinkedList<T>::erase(int index) {
  if(empty() || index < 0) throw OutOfBounds();
  SListNode* first = head->next;
  SListNode* second = head;
  int currentNode = 0;

  if (index == currentNode) {
    head = first;
    delete second;
    return;
  }

  while (first) {
    ++currentNode;
    if (index == currentNode) {
      second->next = first->next;
      delete first;
      return;
    }
    second = first;
    first = first->next;
  }
  throw OutOfBounds();
}

// Reverses elements in list
template <class T>
void SLinkedList<T>::reverse() {
  // If list is empty or has one node, do nothing
  if (head == nullptr || head->next == nullptr)
    return;

  // If list has two or more nodes
  SListNode* second = head;
  SListNode* first = second->next; 
  SListNode* third = nullptr;

  while (first) {
   second->next = third;
   third = second;
   second = first;
   first = first->next; 
  }
  second->next = third;
  head = second;
}

// Removes first occurance of value from list
template <class T>
void SLinkedList<T>::remove_value(T value) {
  if (empty()) return;
  SListNode* firstNode = head;

  if (firstNode->value == value) {
    head = firstNode->next;
    delete firstNode;
    return;
  }

  SListNode* prevNode = firstNode;
  firstNode = firstNode->next;

  while (firstNode) {
    if (firstNode->value == value) {
      prevNode->next = firstNode->next;
      delete firstNode;
      return;
    }
    prevNode = firstNode;
    firstNode = firstNode->next;
  }
  return;
}

}