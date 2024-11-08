#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stack>

// Template class for BinarySearchTree
template <class T>
class BinarySearchTree {
private:
	struct TreeNode {
		T* data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(T* item) : data(item), left(nullptr), right(nullptr) {}
	};

	TreeNode* root;
	int size;

	void reassignNodes(TreeNode* nodePtr) {
		if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
			insert(nodePtr->data);
			delete nodePtr;
			return;
		}
		if (nodePtr->left != nullptr) {
			reassignNodes(nodePtr->left);
		}
		if (nodePtr->right != nullptr) {
			reassignNodes(nodePtr->right);
		}
	}

	void printSubTree(TreeNode* nodePtr) {
		if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
			std::cout << "word: " << nodePtr->data->getWord() << " - count: " << nodePtr->data->getCount() << std::endl;
			return;
		}
		if (nodePtr->left != nullptr) {
			printSubTree(nodePtr->left);
		}
		std::cout << "word: " << nodePtr->data->getWord() << " - count: " << nodePtr->data->getCount() << std::endl;
		if (nodePtr->right != nullptr) {
			printSubTree(nodePtr->right);
		}
	}

public:
	BinarySearchTree();
	~BinarySearchTree();
	T* insert(T*);
	T* find(T* value) const;
	int getSize();
	T* deleteNode(T* value);
	void displayInOrder();

};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
	size = 0;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {

}

template <class T>
T* BinarySearchTree<T>::insert(T* value) {
	TreeNode* newNode = new TreeNode(value);
	if (root == nullptr) {
		root = newNode;
		return root->data;
	}
	TreeNode* nodePtr = root;

	//infinite loop
	while (true) {
		// if word found, increment and return
		if (*(nodePtr->data) == *(newNode->data)) {
			nodePtr->data->addCount();
			return nodePtr->data;
		}
		// if current word is greater than insert word...
		else if (*(nodePtr->data) > *(newNode->data)) {
			// ... and left tree is empty, attach new node, increment size of tree, and return ...
			if (nodePtr->left == nullptr) {
				nodePtr->left = newNode;
				size++;
				return nodePtr->data;
			}
			// else, advance nodePtr to left tree
			else {
				nodePtr = nodePtr->left;
			}
		}
		// if current word is less than insert word...
		else if (*(nodePtr->data) < *(newNode->data)) {
			// ... and right tree is empty, attach new node, increment size of tree, and return ...
			if (nodePtr->right == nullptr) {
				nodePtr->right = newNode;
				size++;
				return nodePtr->data;
			}
			// else, advance nodePtr to right tree
			else {
				nodePtr = nodePtr->right;
			}
		}
	}
}

template <class T>
T* BinarySearchTree<T>::find(T* value) const {
	TreeNode* nodePtr = root;
	while (nodePtr != nullptr) {
		// if word found, return pointer to WordCount
		if (*(nodePtr->data) == *value) {
			return nodePtr->data;
		}
		// if word is alphabetically greater than current word...
		else if (*(nodePtr->data) > *value) {
			// else, advance nodePtr to left tree
			nodePtr = nodePtr->left;
		}
		// if word is alphabetically less than current word...
		else if (*(nodePtr->data) < *value) {
			// else, advance nodePtr to right tree
			nodePtr = nodePtr->right;
		}
	}
	return nullptr;
}

template <class T>
int BinarySearchTree<T>::getSize() {
	return size;
}

template <class T>
T* BinarySearchTree<T>::deleteNode(T* value) {
	TreeNode* nodePtr = root;
	TreeNode* prevPointer = nullptr;
	std::string prevSide = "NULL";
	if(nodePtr )
	while (nodePtr != nullptr) {
		// if word found, return pointer to WordCount
		if (*(nodePtr->data) == *value) {
			if (prevSide == "NULL")
				root = nullptr;
			if (prevSide == "right")
				prevPointer->right = nullptr;
			if (prevSide == "left")
				prevPointer->left = nullptr;
			reassignNodes(nodePtr->left);
			reassignNodes(nodePtr->right);
			T* deletedData = nodePtr->data;
			delete nodePtr;
			return deletedData;
		}
		// if word is alphabetically greater than current word...
		else if (*(nodePtr->data) > *value) {
			// else, advance nodePtr to left tree
			prevPointer = nodePtr;
			prevSide = "left";
			nodePtr = nodePtr->left;
		}
		// if word is alphabetically less than current word...
		else if (*(nodePtr->data) < *value) {
			// else, advance nodePtr to right tree
			prevPointer = nodePtr;
			prevSide = "right";
			nodePtr = nodePtr->right;
		}
	}
	return nullptr;
}

template <class T>
void BinarySearchTree<T>::displayInOrder() {
	TreeNode* nodePtr = root;
	if(nodePtr != nullptr)
		printSubTree(nodePtr);
}
#endif  // BINARYSEARCHTREE_H

// The print format of displayInOrder should be as follows
// std::cout << "word: " << current->data->getWord() << " - count: " << current->data->getCount() << std::endl;

