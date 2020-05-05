#ifndef MY_CODE_CPP_HASH_OBJECT_H_
#define MY_CODE_CPP_HASH_OBJECT_H_

namespace jw {

template <typename K, typename V>
class HashNode {
 public:
  HashNode(K key, V value) {
    this->key = key;
    this->value = value;
  }

  K key;
  V value;
};

}

#endif