#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int>&, const int&);

int main() {
  std::vector<int> sortedValues {1, 12, 65, 98, 99, 201, 365, 2000, 10000};
  int searchKey;

  std::cout << "Enter search value (int): ";
  std::cin >> searchKey;

  if (binarySearch(sortedValues, searchKey))
    std::cout << "Yes, " << searchKey << " is in the vector.\n";
  else
    std::cout << "No, " << searchKey << " is not in the vector.\n";
     
  return 0;
}

bool binarySearch(const std::vector<int> &sV, const int &key) {
  int front = 0,
      back = sV.size() - 1,
      mid;

  while(front <= back) {
    mid = ((unsigned int)front + (unsigned int)back) >> 1;

    if (key == sV[mid])
      return true;
    else if (key < sV[mid])
      back = mid - 1;
    else
      front = mid + 1;    
  }

  return false;
}