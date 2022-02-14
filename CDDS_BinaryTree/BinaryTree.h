#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#pragma once
#include "TreeNode.h"

template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree() {};
	~BinaryTree() {};

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;
	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);
	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);
	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);

	void draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	if (m_root == nullptr)//If there is is a root return root
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	//Crerates a new node and a current node
	TreeNode<T>* newNode = new TreeNode<T>(value);
	TreeNode<T>* currentNode = new TreeNode<T>();

	bool stop = false;

	//Checks if there is a node in the tree if not set new node to be that root
	if (isEmpty())
	{
		m_root = newNode;
		stop = true;
	}
	currentNode = m_root;

	while (stop == false)
	{
		if (newNode->getData() > currentNode->getData())//If current node is less than than new node
		{
			/// <summary>
			/// If currentNode has a right current node is that right
			/// </summary>
			if (currentNode->hasRight())
			{
				currentNode = currentNode->getRight();
			}

			/// <summary>
			/// If currentNode doesnt have a right and new node is greater than current node set new node right of currentnode
			/// </summary>
			if (!currentNode->hasRight() && newNode->getData() > currentNode->getData())
			{
				currentNode->setRight(newNode);
				stop = true;
			}
		}

		if (newNode->getData() < currentNode->getData())//If the current node is greater than the new node
		{
			/// <summary>
			/// If currentNode has a left current node is that left
			/// </summary>
			if (currentNode->hasLeft())
			{
				currentNode = currentNode->getLeft();
			}
			
			/// <summary>
			/// If currentNode doesnt have a left and new node is less than current node set new node left of currentnode
			/// </summary>
			if (!currentNode->hasLeft() && newNode->getData() < currentNode->getData())
			{
				currentNode->setLeft(newNode);
				stop = true;
			}
		}
	}
	
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* currentNode = new TreeNode<T>();
	TreeNode<T>* parentNode = new TreeNode<T>();
	TreeNode<T>* removedNode = new TreeNode<T>();


}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	TreeNode<T>* currentNode = new TreeNode<T>();
	currentNode = m_root;

	/// <summary>
	/// Checks if it is empty
	/// </summary>
	/// <param name="value"></param>
	/// <returns>currentNode</returns>
	if (isEmpty())
	{
		return currentNode;
	}

	//Search while there is a node to compare to
	while (currentNode != nullptr)
	{
		if (currentNode->getData() > value)//If current node is greater than value then search left so get left
		{
			currentNode = currentNode->getLeft();
		}

		if (currentNode->getData() < value)//If currrent node is less than value then search right so get right
		{
			currentNode = currentNode->getRight();
		}
		else
			return currentNode;
			break;
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	bool searching = true;
	//Sets both the parent and current node to be the root
	TreeNode<T>* currentNode = m_root;
	TreeNode<T>* nodeparent = m_root;

	while (searching)
	{
		if (searchValue > currentNode->getData())//If the value is greater then current node check if it has a right
		{
			if (currentNode->hasRight())
			{
				//If it has a right make parent the current node the change current node the the right node.
				nodeparent = currentNode;
				currentNode = currentNode->getRight();
			}
			else if
				break;
		}

		if (searchValue < currentNode->getData())//If the value is less then current node check if it has a right
		{
			if (currentNode->hasLeft())
			{
				nodeparent = currentNode;
				currentNode = currentNode->getLeft();
			}
			else if
				break;
		}

		if (searchValue == currentNode->getData())//IF the value is equal to the currrent node set node found to it and break
		{
			nodeFound = currentNode;
			return true;
			break;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//Decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//Check if the current node is null
	if (currentNode)
	{
		//Draws the left child if this node has one
		if (currentNode->hasLeft())
		{
			//Draws a line betwenn the left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between this child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x,y,(selected == currentNode));
	}
}
