#include <iostream>
#include <string>

#include "SimpleHash.h"

int main() {
  jw::SimpleHash<int, int> hTable;
  hTable.insert(636, 45244);
  hTable.insert(123, 456);
  hTable.insert(30, 13);
  hTable.remove(123);
  std::cout << hTable.exists(30) << "\n";
  std::cout << hTable.exists(123) << "\n";
  try { std::cout << hTable.get(123) << "\n"; } 
    catch(jw::SimpleHash<int, int>::KeyNotFound ex) {
      std::cout << "Key " << ex.key << " not found.\n";
    }
  try { std::cout << hTable.get(636) << "\n"; } 
    catch(jw::SimpleHash<int, int>::KeyNotFound ex) {
      std::cout << "Key " << ex.key << " not found.\n";    
      }
  try { std::cout << hTable.get(30) << "\n"; } 
    catch(jw::SimpleHash<int, int>::KeyNotFound ex) {
      std::cout << "Key " << ex.key << " not found.\n";
    }
  try { std::cout << hTable.get(15) << "\n"; } 
    catch(jw::SimpleHash<int, int>::KeyNotFound ex) {
      std::cout << "Key " << ex.key << " not found.\n";
    };
  //hTable.print_table();
  return 0;
}