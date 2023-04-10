#include <memory>
#include <string>
#include "json.hpp"

class AVL;

class AVLNode {
 public:
 	AVLNode(int key);
 	AVLNode(int key, std::weak_ptr<AVLNode> parent);
 	bool IsLeaf() const;
 	bool HasLeftChild() const;
 	bool HasRightChild() const;
 	void DeleteChild(std::shared_ptr<AVLNode> v);
 	void ReplaceChild(std::shared_ptr<AVLNode> v, std::shared_ptr<AVLNode> u);

 private:
  int key_;
  int height = 0;
  int balanceFactor = 0;
  std::weak_ptr<AVLNode> parent_;
  std::shared_ptr<AVLNode> left_;
  std::shared_ptr<AVLNode> right_;

  friend AVL;
}; // class AVLNode

class AVL {
 public:
 	AVL();

 	void Insert(int key);
 	bool Delete(int key);
 	bool Find(int key) const;
 	std::string JSON() const;
 	size_t size() const;
 	bool empty() const;
 	int DeleteMin();

 private:
	void DeleteLeaf(std::shared_ptr<AVLNode> currentNode);
	int DeleteMin(std::shared_ptr<AVLNode> currentNode);
	void updateAfterInsert(std::shared_ptr<AVLNode> currentNode);
	void changeHeightAndBF(std::shared_ptr<AVLNode> currentNode);
	void Balance(std::shared_ptr<AVLNode> currentNode, std::shared_ptr<AVLNode> previousNode, std::shared_ptr<AVLNode> prePreNode);
	void RightRotate(std::shared_ptr<AVLNode> currentNode, std::shared_ptr<AVLNode> previousNode);
	void LeftRotate(std::shared_ptr<AVLNode> currentNode, std::shared_ptr<AVLNode> previousNode);

 	std::shared_ptr<AVLNode> root_;
 	size_t size_;
}; // class AVL