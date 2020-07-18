#ifndef BST_H_
#define BST_H_

namespace jw {

struct BSTNode {
  int data;
  BSTNode* parent;
  BSTNode* right;
  BSTNode* left;

  BSTNode(int nData, BSTNode* newParent, BSTNode* newLeft, BSTNode* newRight) {
    this->data = nData;
    this->parent = newParent;
    this->left = newLeft;
    this->right = newRight;
  }
};

class BST {
 public:
  BST() { this->root = nullptr; }
  ~BST() { this->deleteTree(); }

  void insert(const int);
  void printValues();
  void deleteTree();
  void deleteValue(const int);

  int getNodeCount();
  int getHeight();
  int getMinValue();
  int getMaxValue();
  int getSuccessorValue(const int);

  bool isInTree(const int);
  bool isBST();
  
 private:
  BSTNode* root;

  // Private, utility functions
  void recursiveInsert(const int, BSTNode*);
  void recursivePrintValues(BSTNode*);
  void recursiveDeleteTree(BSTNode*);
  BSTNode* recursiveDeleteValue(const int, BSTNode*);
  BSTNode* getMinNode(BSTNode*);
  BSTNode* getMaxNode(BSTNode*);
  int recursiveNodeCounter(BSTNode*);
  int recursiveHeightCounter(BSTNode*);
  bool recursiveSearch(const int, BSTNode*);
  bool recursiveIsBT(BSTNode*, int, int);
  BSTNode* getKeyNode(int, BSTNode*);
  BSTNode* getSuccessorNode(BSTNode*);
};

}

#endif