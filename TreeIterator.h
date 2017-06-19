/** @file TreeIterator.h
@brief Contains the class declarations for TreeIterator class.
@author Lisa Chiang
@date March 14, 2017

TreeIterator allows you to traverse through the BinarySearchTree class to access TreeNodes via node pointers.
*/

#ifndef TreeIterator_h
#define TreeIterator_h

#include "BinarySearchTree.h"
#include "TreeNode.h"

class TreeNode; 
class BinarySearchTree; 

class TreeIterator {
	friend class BinarySearchTree; 
public: 
	//Constructor
	TreeIterator(TreeNode* temp, BinarySearchTree* I); 

	//Operators 
	TreeIterator& operator ++ ();
	TreeIterator operator++(int unused);
	TreeIterator& operator --();
	TreeIterator operator--(int unused);
	int operator* ();

	//Comparisons
	bool operator == (const TreeIterator& B);
	bool operator != (const TreeIterator& B);

private: 
	TreeNode* position; 
	BinarySearchTree* tree; 


};

#endif