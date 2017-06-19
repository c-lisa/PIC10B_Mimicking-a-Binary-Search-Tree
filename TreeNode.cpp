/** @file TreeNode.cpp
@brief Contains the class definitions for TreeNode class.
@author Lisa Chiang
@date March 14, 2017

TreeNode creates different TreeNodes that contain integer data that have an TreeIterator pointing to the TreeNode.
TreeNodes are linked to one another and these links can be traversed using TreeIterators.
*/

#include "TreeNode.h"

//Constructors
/**@brief TreeNode Default Constructor

Default constructor creates a TreeNode and initializes variables by default.

@param No parameters.
@return No Returns.
*/
TreeNode::TreeNode()
{
	data = 0;
}
/**@brief TreeNode Constructor

Constructs a TreeNode with initial value given by the input argument.

@param data_input is user given data to create a TreeNode.
@return No Returns.
*/
TreeNode::TreeNode(int data_input)
{
	data = data_input;
}

//Mutators
/**@brief Insert_node

Inserts a new TreeNode* relative to the root TreeNode. All the smaller nodes
go on the left and all the larger nodes go on the right. 

@param new_node is a pointer to the new TreeNode that will be created. 
@return Returns nothing. 
*/
void TreeNode::insert_node(TreeNode* new_node)
{
	if (data == new_node->data) 
	{
		return; 
	}
	//if the input's data is less than implicit parameter's data, then LEFT HAND INSERT 
	if (new_node->data < data)
	{
		//if node is childless, then just add new node on left 
		if (left == NULL)
		{
			left = new_node;
			new_node->parent = this; //what's this? 
			new_node->left = NULL; 
			new_node->right = NULL; 
		}
		//if node is not childless, call insert_node on current node - recurse
		else
		{
			left->insert_node(new_node); 
		}
	}
	//if the input's data is greater than implicit parameter's data, then RIGHT HAND INSERT 
	else if (data < new_node->data)
	{
		//if node is childless, then just add new node on right
		if (right == NULL)
		{
			right = new_node;
			new_node->parent = this; //what's this? 
			new_node->left = NULL;
			new_node->right = NULL;
		}
		//if node is not childless, call insert_node on current node - recurse
		else
		{
			right->insert_node(new_node);
		}
	}
	return; 
}

//Accessors
/**@brief Find node 

Traverses through tree to check if a value exists

@param value is the integer we are looking for in the Tree. 
@return Returns true if value is found.
*/
bool TreeNode::find(int value) const
{
	if (value < data) //check left side of tree
	{
		if (left == NULL)
		{
			return false; 
		}
		else
		{
			return left->find(value); 
		}
	}
	else if (data < value) //check right side of tree
	{
		if (right == NULL)
		{
			return false; 
		}
		else
		{
			return right->find(value); 
		}
	}
	else return true; 
}
/**@brief Smallest in the Subtree

Looks for the smallest child in a subtree. 

@param No parameters. 
@return Returns a pointer to the smallest TreeNode in a subtree.
*/
TreeNode* TreeNode::smallest_in_subtree()
{
	//if you have a left child, you go all the way down to the left until null. if you don't have left children, you return yourself
	TreeNode* current = this; 
	while (current->left)
	{
		current = current->left;
	}
	return current;
}
/**@brief Next Smallest

Looks for the next smallest integer in reference to whatever TreeNode
called the function. 

@param No parameters.
@return Returns a pointer to the next smallest TreeNode. 
*/
TreeNode* TreeNode::next_smallest()
{
	/* 1. you have no kids (no right descendants) -> return parent 2. you hae a right child -> find smallest in subtree 3. you are the rightmost node -> return nullptr */
	if (right) //you have a right child
	{
		return right->smallest_in_subtree(); 
	}
	if (this == parent->left) //if you have no right child 
	{
		return parent; 
	}
	else //you are the right most node 
	{
		return nullptr; 
	}
}
/**@brief Greatest in the Subtree

Looks for the greatest child in a subtree.

@param No parameters.
@return Returns a pointer to the greatest TreeNode in a subtree.
*/
TreeNode* TreeNode::greatest_in_subtree()
{
	/*if you have a RIGHT child, you go all the way down until you reach null. if you don't have any right children, you return yourself. */
	TreeNode* current = this; 
	while (current->right)
	{
		current = current->right; 
	}
	return current; 
}
/**@brief Previous greatest

Looks for the previous largest integer in reference to whatever TreeNode
called the function.

@param No parameters.
@return Returns a pointer to the previous largest TreeNode.
*/
TreeNode* TreeNode::previous_greatest()
{
	/* 1. you have no kids (no left descendants) -> return next smallest ancestor	2. you have a left child -> find greatest in subtree	3. you are the leftmost node -> return nullptr	*/ 
	if (left) //you have a left child
	{
		return left->greatest_in_subtree(); 
	}
	if (this == parent -> right)
	{
		return parent; 
	}
	else
	{
		return nullptr; 
	}
}

//Operators 
/**@brief TreeNode * operator

Returns the value of the TreeNode.

@param No parameters.
@return data is an integer that the TreeNode contains.
*/
int TreeNode::operator*()
{
	return data; 
}