// Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

#include <iostream>
#include <string>
#include <unordered_map>

bool isUnique(const std::string&);

int main() {
  std::string entry ="";

  while (true) {
    std::cout << "Enter string (ctrl+c to quit): ";
    std::getline(std::cin, entry);

    if (isUnique(entry)) {
      std::cout << "All characters in that string are unique.\n\n";
    } else {
      std::cout << "There are duplicates characters in that string.\n\n";
    }
  }

  return 0;
}

bool isUnique(const std::string& sentence) {
  std::unordered_map<char, bool> charMap;
  int sentenceLength = sentence.length();

  for (int index = 0; index < sentenceLength; index++) {
    if (charMap.find(sentence[index]) == charMap.end()) {
      charMap.insert({sentence[index], true});
    } else {
      return false;
    }
  }
  return true;
}