#ifndef J_VECTOR_H_
#define J_VECTOR_H_

#include <cstdlib> // malloc, free
#include <cmath> // log2, ceil, pow

namespace jw {

template <class T>
class jVector {
 public:
  jVector();
  jVector(int capacity);
  ~jVector();

  int size();
  int capacity();
  int find(T value);

  bool is_empty();
  
  T at(int index);
  T pop();

  void push_back(T value);
  void insert(int index, T value);
  void prepend(T value);
  void delete_at(int index);
  void remove(T value);
  
  // Exception Classes
  class MemAllocError {};
  class InvalidIndex {};

 private:
  int arrSize;
  int arrCapacity;
  T* arr;

  void resize(int new_capacity);
};

}

// Default Constructor
template <class T>
jw::jVector<T>::jVector() {
  arrSize = 0;
  arrCapacity = 16;

  arr = (T*) std::malloc(arrCapacity * sizeof(T));
  if (!arr) throw jw::jVector<T>::MemAllocError();
}

// Constructor
template <class T>
jw::jVector<T>::jVector(int capacity) {
  arrSize = 0;

  if (capacity < 0)
    this->arrCapacity = 16;
  else
    this->arrCapacity = pow(2, ceil(log2(capacity)));
  
  arr = (T*) std::malloc(arrCapacity * sizeof(T));
  if (!arr) throw jw::jVector<T>::MemAllocError();
}

// Destructor
template <class T>
jw::jVector<T>::~jVector() {
  std::free(arr);
}

// Returns number of elements stored in the jvector
template <class T>
int jw::jVector<T>::size() {
  return this->arrSize;
}

// Returns number of elements jvector can currently hold
template <class T>
int jw::jVector<T>::capacity() {
  return this->arrCapacity;
}

// Searches jvector for value and returns index if found, otherwise -1
template <class T>
int jw::jVector<T>::find(T value) {
  for (int i = 0; i < arrSize; i++) {
    if (*(arr+i) == value)
      return i;
  }
  return -1;
}

// Returns true if jvector has no elements, otherwise false
template <class T>
bool jw::jVector<T>::is_empty() {
  return this->arrSize == 0;
}

// Returns element at given index
template <class T>
T jw::jVector<T>::at(int index) {
  if (index < 0 || index >= arrSize) throw jw::jVector<T>::InvalidIndex();
  return *(arr+index);
}

// Returns and removes end value of jvector
template <class T>
T jw::jVector<T>::pop() {
  if (is_empty()) return T();
  T temp = *(arr+(arrSize-1));
  *(arr+(arrSize-1)) = T();

  if (arrSize  <= (0.25 * arrCapacity)) resize(arrCapacity / 2);
  --arrSize;
  return temp;
}

// Inserts value at the end of the jvector
template <class T>
void jw::jVector<T>::push_back(T value) {
  if (arrSize == arrCapacity) resize(arrCapacity * 2);

  *(arr+arrSize) = value;
  arrSize++;
}

// Inserts value at given index, shifts trailing to the right
template <class T>
void jw::jVector<T>::insert(int index, T value) {
  if (index < 0 || index >= arrSize) throw jw::jVector<T>::InvalidIndex();
  if (arrSize == arrCapacity) resize(arrCapacity * 2);

  // Shift postindex values right
  for (int i = arrSize-1; i >= index; i--)
    *(arr+i+1) = *(arr+i);
  
  // Change value at index to given value
  *(arr+index) = value;
  ++arrSize;
}

// Inserts given values at beginning of jvector
template <class T>
void jw::jVector<T>::prepend(T value) {
  insert(0, value);
}

// Deletes an element at given index. Shifts trailing elements left
template <class T>
void jw::jVector<T>::delete_at(int index) {
  if (index < 0 || index >= arrSize) throw jw::jVector<T>::InvalidIndex();

  for (int i = index; i < arrSize-1; i++) 
    *(arr+i) = *(arr+(i+1));
  *(arr+(arrSize-1)) = T(); // Remove value from end - overflow protection
  --arrSize;
  if (arrSize  <= (0.25 * arrCapacity)) resize(arrCapacity / 2);
}

// Removes all occurances of value from jvector
template <class T>
void jw::jVector<T>::remove(T value) {
  if (is_empty()) return;
  for (int i = 0; i < arrSize; i++) {
    if (*(arr+i) == value)
      delete_at(i);
  }
  if (arrSize  <= (0.25 * arrCapacity)) resize(arrCapacity / 2);
}

// Private resize member function
template <class T>
void jw::jVector<T>::resize(int new_capacity) {
  T* tempArr = (T*) malloc(new_capacity * sizeof(T));
  if(!tempArr) throw jw::jVector<T>::MemAllocError();

  for (int i = 0; i < arrSize; i++)
    *(tempArr+i) = *(arr+i);

  std::free(arr);
  arr = tempArr;
  arrCapacity = new_capacity;
}
#endif