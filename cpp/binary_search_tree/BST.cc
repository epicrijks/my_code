#include <iostream>
#include <cmath>
#include "BST.h"

namespace jw {

// Insert node into BST with given data value
void BST::insert(const int newData) {
  if (newData < 0) {
    std::cout << "Invalid entry.";
  } else if (root == nullptr) {
    root = new BSTNode(newData, nullptr, nullptr, nullptr);
  } else {
    recursiveInsert(newData, root);
  }
}

// Private recursive, utility function to transverse for insertion (no dups)
void BST::recursiveInsert(const int newData, BSTNode* node) {
  if (newData == node->data) return;
  
  if (newData < node->data) {
    if (node->left == nullptr)
      node->left = new BSTNode(newData, node, nullptr, nullptr);
    else
      recursiveInsert(newData, node->left);
  }
  else if (newData > node->data) {
    if (node->right == nullptr)
      node->right = new BSTNode(newData, node, nullptr, nullptr);
    else 
      recursiveInsert(newData, node->right);
  }
}

// Print entire BST inorder (sorted)
void BST::printValues() {
  if (root == nullptr)
    std::cout << "BST is empty.";
  else
    recursivePrintValues(root);  
}

// Private recursive, utility function for printing values
void BST::recursivePrintValues(BSTNode* node) {
  if (node->left != nullptr)
    recursivePrintValues(node->left);
  
  std::cout << node->data << " ";

  if (node->right != nullptr)
    recursivePrintValues(node->right);
}

// Delete entire tree 
void BST::deleteTree() {
  if (root != nullptr) {
    recursiveDeleteTree(root);
    root = nullptr;
  }
  std::cout << "Tree deleted.";
}

// Private recursive, utility for deleting entire tree
void BST::recursiveDeleteTree(BSTNode* node) {
  if (node->left != nullptr)
    recursiveDeleteTree(node->left);
  
  if (node->right != nullptr)
    recursiveDeleteTree(node->right);

  node->left = node->right = nullptr;
  delete node;
}

// Delete given value from tree
void BST::deleteValue(const int val) {
  root = recursiveDeleteValue(val, root);
}

// Private recursive, utility for deleting given value
BSTNode* BST::recursiveDeleteValue(const int value, BSTNode* node) {
  if (node == nullptr) return node;
  
  if (value < node->data) {
    node->left = recursiveDeleteValue(value, node->left);
  } else if (value > node->data) {
    node->right = recursiveDeleteValue(value, node->right);
  } else {
    node->left = recursiveDeleteValue(value, node->left);

    // One child or no children
    if (node->left == nullptr) {
      BSTNode* temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      BSTNode* temp = node->left;
      delete node;
      return temp;
    }

    // Two children
    BSTNode* temp = getMinNode(node->right);
    node->data = temp->data;
    node->right = recursiveDeleteValue(temp->data, node->right);
  }
  return node;
}

// Private function which returns node with smallest value in given tree
BSTNode* BST::getMinNode(BSTNode* node) {
  if (node->left == nullptr)
    return node;
  else
    return getMinNode(node->left);
}

// Private function which returns node with largest value in given tree
BSTNode* BST::getMaxNode(BSTNode* node) {
  if (node->right == nullptr)
    return node;
  else
    return getMaxNode(node->right);
}

// Returns number of nodes in BST
int BST::getNodeCount() {
  if (root == nullptr)
    return 0;
  else 
    return recursiveNodeCounter(root);
}

// Private recursive, utility function to count nodes in tree
int BST::recursiveNodeCounter(BSTNode* node) {
  if (node == nullptr) 
    return 0;
  return recursiveNodeCounter(node->left)+recursiveNodeCounter(node->right) + 1;
}

// Returns tree height (node based)
int BST::getHeight() {
  if (root == nullptr)
    return 0;
  else
    return recursiveHeightCounter(root);
}

// Private recursive, utility function to find height
int BST::recursiveHeightCounter(BSTNode* node) {
  if (node == nullptr)
    return 0;
  else
    return std::max(recursiveHeightCounter(node->left), 
                    recursiveHeightCounter(node->right)) + 1;
  
}

// Returns minimum value of BST (-1 if empty)
int BST::getMinValue() {
  if (root == nullptr)
    return -1;
  else
    return getMinNode(root)->data;
}

// Returns maximum value of BST (-1 if empty)
int BST::getMaxValue() {
  if (root == nullptr)
    return -1;
  else
    return getMaxNode(root)->data;
}

// Returns next highest value in BST after given value
int BST::getSuccessorValue(const int value) {
  BSTNode* keyNode = getKeyNode(value, root);

  if (!keyNode)
    return -1;
  else {
    BSTNode* succ = getSuccessorNode(keyNode);  
    if (succ == nullptr)
      return -1;
    else
      return succ->data;    
  }
}

// Private utility function to find node with given value
BSTNode* BST::getKeyNode(int key, BSTNode* node) {
  if (node == nullptr)
    return nullptr;
  
  if (key == node->data)
    return node;
  else if (key < node->data)
    return getKeyNode(key, node->left);
  else
    return getKeyNode(key, node->right);
}

// Private utility function to find node of successor
BSTNode* BST::getSuccessorNode(BSTNode* keyNode) {
  if (keyNode->right != nullptr)
    return getMinNode(keyNode->right);

  BSTNode* p = keyNode->parent;
  while (p != nullptr && keyNode == p->right) {
    keyNode = p;
    p = p->parent;
  }

  return p;
}

// Returns true if given value exists in BST
bool BST::isInTree(const int value) {
  if (root == nullptr)
    return false;

  return recursiveSearch(value, root);
}

// Private, recursive, utility function to search for value in tree
bool BST::recursiveSearch(const int value, BSTNode* node) {
  if (node == nullptr) 
    return false;
  else if (value == node->data) 
    return true;
  else if (value < node->data)
    return recursiveSearch(value, node->left);
  else
    return recursiveSearch(value, node->right); 
}

// Returns true if binary tree is a BST
bool BST::isBST() {
  return recursiveIsBT(root, 0, INT_MAX);
}

// Private, recursive, utility function to determine if BST
bool BST::recursiveIsBT(BSTNode* node, int min, int max) {
  if (node == nullptr)
    return true;

  if (node->data < min || node->data > max)
    return false;

  return recursiveIsBT(node->left, min, node->data-1) &&
         recursiveIsBT(node->right, node->data+1, max);
}

}