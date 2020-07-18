#include <iostream>
#include <vector>
#include "BST.H"

int main() {
  jw::BST binTree;
  int val;
  std::vector<int> values {15, 10, 25, 13, 11, 100, 1, 2, 14, 13, 81, 12};;

  for (int& v: values) { binTree.insert(v); }
  binTree.printValues();
  std::cout << std::endl;

  while (true) {
    std::cout << "Enter value to find successor: ";
    std::cin >> val;
    std::cout << "Successor of " << val 
              << " is " << binTree.getSuccessorValue(val) << std::endl;
  }
  std::cout << std::endl;
  return 0;
}