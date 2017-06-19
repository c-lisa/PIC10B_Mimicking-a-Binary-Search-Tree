/** @file TreNode.h
@brief Contains the class declarations for TreeNode class.
@author Lisa Chiang
@date March 7, 2017

TreeNode creates different TreeNodes that contain integer data that have an TreeIterator pointing to the TreeNode.
TreeNodes are linked to one another and these links can be traversed using TreeIterators.
*/

#ifndef TreeNode_h
#define TreeNode_h

#include "BinarySearchTree.h"
#include "TreeIterator.h"
#include <iostream>

class TreeNode {
	friend class BinarySearchTree;
	friend class TreeIterator; 

public:
	//Constructors 
	TreeNode();
	TreeNode(int data_input);

	//Mutators
	void insert_node(TreeNode* new_node);
	
	//Accessors
	bool find(int value) const;
	TreeNode* smallest_in_subtree();
	TreeNode* next_smallest();
	TreeNode* greatest_in_subtree(); 
	TreeNode* previous_greatest(); 

	//Operators 
	int operator*();

private:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent; 
};

#endif 
