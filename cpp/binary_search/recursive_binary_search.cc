#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int>&, const int&, int, int);

int main() {
  std::vector<int> sortedValues {1, 12, 65, 98, 99, 201, 365, 2000, 10000};
  int searchKey;

  std::cout << "Enter search value (int): ";
  std::cin >> searchKey;

  if (binarySearch(sortedValues, searchKey, 0, sortedValues.size() - 1))
    std::cout << "Yes, " << searchKey << " is in the vector.\n";
  else
    std::cout << "No, " << searchKey << " is not in the vector.\n";
     
  return 0;
}

bool binarySearch(const std::vector<int> &sV, const int &key, int front, int back) {
  if (front > back) {
    return false;
  }
  else {
    int mid = ((unsigned int)front + (unsigned int)back) >> 1;

    if (key == sV[mid])
      return true;
    else if (key < sV[mid])
      return binarySearch(sV, key, front, mid - 1);
    else
      return binarySearch(sV, key, front + 1, back);
  } 
}