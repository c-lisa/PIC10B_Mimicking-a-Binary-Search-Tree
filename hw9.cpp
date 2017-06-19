/** @file main.cpp
@brief Mimics the function of a greatly simplified Binary Search Tree class.
@author Lisa Chiang
@date March 14, 2017

Creates treenodes on a binary search tree. Allows user to print, traverse through tree, erase, insert, etc. treenodes. 
*/

#include <iostream>
#include "BinarySearchTree.h"
#include "TreeIterator.h"
#include "TreeNode.h"

int main()
{
	BinarySearchTree bst; 
	bst.insert(3); bst.insert(2); bst.insert(11); 
	bst.insert(13); bst.insert(5); bst.insert(17);
		
	//Prints to console: 2, 3, 5, 11, 13, 17
	int size = 1;
	for (auto x : bst)
	{
		std::cout << x; 
		if (size != 6)
		{
			std::cout << ", ";
		}
		size++;
	}
	std::cout << std::endl; 
	
	bst.erase(6); // {2,3,5,11,13,17} no effect
	bst.erase(11); // {2,3,5,13,17} 
	
	auto start = std::begin(bst); 
	auto stop = std::end(bst); 
	
	int value = 17; 
	bool keep_looking = true; 
	
	//Find a 17 in the list 
	while ((start != stop) && keep_looking)
	{
		if (*start == value)
		{
			keep_looking = false; 
			--start; 
		}
		++start; 
	}
	
	//Prints "17 is in the list" 
	if (start != stop)
	{
		std::cout << *start << " is in the list." << std::endl;
	}

	return 0; 
}