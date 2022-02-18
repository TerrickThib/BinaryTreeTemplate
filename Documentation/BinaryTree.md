**Terrick Thibodeaux**  
S218032
Binary Tree  
Algorithms and Data Structures C++ 
# I.Requirments  
**1.Description of Problem**  

**Problem Statment:**  
The creation of a Binary Tree that allows the user to insert numbers that will be sorted based on the first number entered. It will also allow the user to remove any number is the tree.  

**Problem Specifications:**  
- Should be able to insert a number using insert function  

- That number should be set as the root then later be placed based on that root  

- Shows use of remove function   

- Displays use of bianary trees in C++    

**Input Information** 
- Takes in users value 
- Takes in user option to insert or remove  

**Output Information**  
- The users value where it will fit based on the root  
- Displays Bianary tree based on values inputed and removed  

**User Interface Information**
- Displays the values the user adds to the tree  

# II.Design  
1. *System Architecture*   

Uses Binary trres as well as functions to complete application  

2. *Object Information*  
- **File Name:** TreeNode.h   

Name: TreeNode()  
Discription: Is the base Constructer  
Visablity: Public

Name: TreeNode(T value)  
Discription: Is another base constructer that takes in T value  
Visablity: Public

Name: hasLeft()  
Discription: Returns whether or not this node has a left child   
Visablity: Public  

Name: hasRight()  
Discription: Returns whether or not this node has a right child  
Visablity: Public  

Name: getData()     
Discription: Returns the data this node contains  
Visablity: Public  

Name: getLeft()  
Discription: Gets the child to the left of this node  
Visablity: Public  

Name: getRight()  
Discription: Gets the child to the right of this node  
Visablity: Public  

Name: setData(T value)  
Discription: Sets the value of the data this node is storing to be the given value  
Visablity: Public  

Name: setLeft(TreeNode<T>* node);  
Discription: Sets the left child of this node to be the given node  
Visablity: Public  

Name: setRight(TreeNode<T>* node)  
Discription: Sets the left child of this node to be the given node  
Visablity: Public  

Name: draw(int x, int y, bool selected = false)  
Discription: Draws at the point given  
Visablity: Public  

- **File Name** BinaryTree.h 

Name: BinaryTree()  
Discription: Is the base constructer  
Visablity: Public  

Name: isEmpty() const  
Discription: Returns whether or not there are any nodes in the list  
Visablity: Public  

Name: insert(T value)  
Discription: Creates a new node that stores the given value and places it into the tree  
Visablity: Public  

Name: remove(T value)  
Discription: Finds the node with the given value and removes it from the tree  
Visablity: Public  

Name: find(T value)  
Discription: Finds and returns a node with the given value in the tree  
Visablity: Public  

Name: draw(TreeNode<T>* selected = nullptr)  
Discription: Base constructer for draw  
Visability: Public  

Name: findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)  
Discription: Finds the node that matches the value in the list  
Visablity: Private  

Name: draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr)  
Discription: draws the nodes for binary tree  
Visablity: Private  




