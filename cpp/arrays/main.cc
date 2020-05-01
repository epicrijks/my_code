#include <iostream>

#include "jVector.h"

template <class T>
void printJVector(jw::jVector<T> &vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec.at(i) << " ";

  std::cout << "\n";
}

int main() {
  jw::jVector<double> scores;
  srand(time(0));
  for (int i = 0; i < 16; i ++) {
    scores.push_back(rand()%100+1);
  }
  printJVector(scores);
  std::cout << "Capacity: " << scores.capacity() << "\n";
  scores.insert(5, 3.14);
  printJVector(scores);
  std::cout << "Capacity: " << scores.capacity() << "\n";


  std::cout << "3.14 is at pos: " << scores.find(3.14) << "\n";
  std::cout << "Pop: " << scores.pop() << "\n";
  printJVector(scores);

  scores.push_back(15);
  scores.prepend(1.25);
  printJVector(scores);

  scores.delete_at(6);
  scores.push_back(1.25);
  printJVector(scores);
  scores.remove(1.25);
  printJVector(scores);
  std::cout << "Capacity: " << scores.capacity() << "\n";
  std::cout << "Size: " << scores.size() << "\n";

  for (int i = 0; i < 8; i++)
    scores.delete_at(i);
  printJVector(scores);
  std::cout << "Capacity: " << scores.capacity() << "\n";
  
  
  return 0;
}