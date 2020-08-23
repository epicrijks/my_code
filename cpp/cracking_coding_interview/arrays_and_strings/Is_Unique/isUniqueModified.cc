#include <iostream>
#include <string>

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
  int sentenceLength = sentence.length();

  for (int i = 0; i < sentenceLength-1; i++) {
    for (int j = i+1; j < sentenceLength; j++) {
      if (sentence[i] == sentence[j]) {
        return false;
      }
    }
  }
  return true;
}