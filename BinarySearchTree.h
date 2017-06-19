/** @file BinarySearchTree.h
@brief Contains the class declarations for BinarySearchTree class.
@author Lisa Chiang
@date March 14, 2017

BinarySearchTree allows the user to store ints as nodes that are accessed by iterating through the BinarySearchTree. The BinarySearchTree
can be manipulated by the user.
*/

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "TreeNode.h"
class TreeNode;
#include "TreeIterator.h"
class TreeIterator;
#include <algorithm>

class BinarySearchTree {
	friend class TreeIterator; 

public:
	//Constructor 
	BinarySearchTree();

	//Destructor
	~BinarySearchTree(); 
		
	//Iterator Functions 
	TreeIterator begin();
	TreeIterator end(); 
	
	//Non-Iterator Functions 
	void insert(int value);
	void erase(int value);
	int count(int value) const; 
	
	int smallest();
	int largest();


private:
	TreeNode* root; 
	size_t size; 
};

#endif