/** @file TreeIterator.h
@brief Contains the class definitions for TreeIterator class.
@author Lisa Chiang
@date March 14, 2017

TreeIterator allows you to traverse through the BinarySearchTree class to access TreeNodes via node pointers.
*/
#include "TreeIterator.h"

//Constructor
/**@brief TreeIterator Constructor

Creates an TreeIterator pointing to the input TreeNode.

@param temp is a pointer to the user created TreeNode.
@param I is the pointer to a specific BinarySearchTree
@return No returns.
*/
TreeIterator::TreeIterator(TreeNode* temp, BinarySearchTree* I)
{
	position = temp; 
}

//Operators
/**@brief ++Prefix

Increments the iterator to the next TreeNode. If the TreeIterator is currently pointing 
to a childless TreeNode, then do nothing. 

@param No parameters.
@return Returns an TreeIterator pointing to next TreeNode.
*/
TreeIterator& TreeIterator::operator ++ ()
{
	/*
	if you're a left child and you have no children, you go back to node above
	if you have two children you go to right child
	if you're right child
	*/
	position = position->next_smallest();
	return *this; 
}
/**@brief Postfix++

Increments the TreeIterator to the next TreeNode. If the TreeIterator is currently pointing to 
a childless TreeNode, then do nothing.

@param Unused integer that differentiates from prefix.
@return Returns a TreeIterator pointing to next Treenode.
*/
TreeIterator TreeIterator::operator++(int unused)
{
	TreeIterator clone(*this); 
	++(*this); 
	return clone; 
}
/**@brief --Prefix

Decrements the TreeIterator to the previous TreeNode. If the TreeIterator is currently pointing to
the left-most TreeNode, then do nothing.

@param No parameters.
@return Returns an TreeIterator pointing to previous Treenode.
*/
TreeIterator& TreeIterator::operator --()
{
	position = position->previous_greatest();
	return *this; 
}
/**@brief Postfix--

Increments the TreeIterator to the next TreeNode. If the TreeIterator is currently pointing to the
left-most node, then do nothing.

@param Unused integer that differentiates from prefix.
@return Returns an TreeIterator pointing to previous TreeNode.
*/
TreeIterator TreeIterator::operator--(int unused)
{
	TreeIterator clone(*this);
	--(*this);
	return clone;
}
/**@brief TreeIterator * operator

Returns the value contained in the TreeNode currently pointed to by the TreeIterator.

@param No parameters.
@return Returns the int of the TreeNode that the TreeIterator is pointing to.
*/
int TreeIterator::operator* ()
{
	if (position != nullptr)
	{
		return position->data; 
	}
	else
	{
		return -1;
	}
}

//Comparisons
/**@brief TreeIterator == operator

Checks if two TreeIterators are pointing to the same element.

@param B is the TreeIterator that is being compared to the implict TreeIterator.
@return Returns true if they are equal and false otherwise.
*/
bool TreeIterator::operator == (const TreeIterator& B)
{
	if (position == B.position)
	{
		return true; 
	}
	else return false; 
}
/**@brief TreeIterator != operator

Checks if two TreeIterators are not pointing to the same element.

@param B is the TreeIterator that is being compared to the implict TreeIterator.
@return Returns false if they are equal and true otherwise.
*/
bool TreeIterator::operator != (const TreeIterator& B)
{
	if (position == B.position)
	{
		return false;
	}
	else return true;
}