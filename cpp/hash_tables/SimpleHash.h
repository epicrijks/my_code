// Simple implmentation of a *static* hash table data type.
// Set to hold 31 elements

#ifndef MY_CODE_CPP_SIMPLE_HASH_H_
#define MY_CODE_CPP_SIMPLE_HASH_H_

#include "HashNode.h"

namespace jw {

template <typename K, typename V>
class SimpleHash {
 public:
  SimpleHash();
  ~SimpleHash();

  void insert(K key, V value);
  V remove(K key);
  void print_table() const;
  V get(K key);
  bool exists(K key);

  // Exception Classes
  class MemAllocError {};
  class TableFull {};
  class TableEmptyError {};
  class KeyNotFound { 
   public:
    KeyNotFound(K key) : key(key) {}; 
    K key; 
  };

 private:
  int capacity;
  int size;
  HashNode<K, V>** hashTable;
  HashNode<K, V>*  dummy;

  // void resize(int new_size); // Will implemement in later versions
  int hash(K key);
};


// Default Constructor
template <typename K, typename V>
SimpleHash<K, V>::SimpleHash() {
  capacity = 31;
  size = 0;

  if (!(hashTable = new HashNode<K, V>*[capacity])) throw MemAllocError();

  for (int i = 0; i < capacity; i++)
    hashTable[i] = nullptr;

  if (!(dummy = new HashNode<K, V>(-1, -1))) throw MemAllocError();
}

// Destructor
template <typename K, typename V>
SimpleHash<K, V>::~SimpleHash() {
  for (int i = 0; i < capacity; i++) {
    if (hashTable[i])
      delete hashTable[i];
  }
}

// Hash function
template <typename K, typename V>
int SimpleHash<K, V>::hash(K key) {
  return key % capacity;
}

// Insert new key, value pair
// Major chunking concerns if not but a "simple" hash table
template <typename K, typename V>
void SimpleHash<K, V>::insert(K key, V value) {
  if (size == capacity) throw TableFull();
  HashNode<K, V>* temp = new HashNode<K, V>(key, value);

  if (!temp) 
    throw MemAllocError();

  int hashIndex = hash(key);

  // If the space is occupied, and its key is not -1 or current key, move on
  while (hashTable[hashIndex] && hashTable[hashIndex]->key != -1 &&
                                         hashTable[hashIndex]->key != key) {
    hashIndex++;
    hashIndex %= capacity; // This is ugly and creates chunking, but okay.
  }

  // If the space is empty or dummy, the size on the table increases
  if (!hashTable[hashIndex] || hashTable[hashIndex]->key == -1)
    size++;

  hashTable[hashIndex] = temp;
}

// Removes node and returns value based on key
// Returns -1 if key not found
template <typename K, typename V>
V SimpleHash<K, V>::remove(K key) {
  if (size == 0) throw TableEmptyError();

  int hashIndex = hash(key);

  while (hashTable[hashIndex]) {
    if(hashTable[hashIndex]->key == key) {
      V tempValue = hashTable[hashIndex]->value;
      size--;
      delete hashTable[hashIndex];
      hashTable[hashIndex] = dummy;
      return tempValue;
    }
    hashIndex++;
    hashIndex %= capacity;
  }
  throw KeyNotFound(key);
}

// Gets value from node with given key
template <typename K, typename V>
V SimpleHash<K, V>::get(K key) {
  int hashIndex = hash(key);

  while (hashTable[hashIndex]) {
    if(hashTable[hashIndex]->key == key) {
      return hashTable[hashIndex]->value;
    }
    hashIndex++;
    hashIndex %= capacity;
  }
  throw KeyNotFound(key);
}

// Returns true if key exists in table; otherwise, false
template <typename K, typename V>
bool SimpleHash<K, V>::exists(K key) {
  int hashIndex = hash(key);

  while (hashTable[hashIndex]) {
    if(hashTable[hashIndex]->key == key) {
      return true;
    }
    hashIndex++;
    hashIndex %= capacity;
  }
  return false;
}

// Prints contents of hash table
template <typename K, typename V>
void SimpleHash<K, V>::print_table() const {
  for (int i = 0; i < capacity; i++) {
    std::cout << i;
    if (hashTable[i]) {
     std::cout << " --> Key: " << hashTable[i]->key 
                << "; Value: " << hashTable[i]->value;
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}


}

#endif