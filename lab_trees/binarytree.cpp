/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include <algorithm>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
   mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node * root){
    if(root==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    Node * swap = root->left;
    root->left = root->right;
    root->right = swap;
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    std::vector<T> order;
    InorderTraversal<T> iot(root);
    for(typename InorderTraversal<T>::Iterator it = iot.begin(); it!=iot.end();++it){
        order.push_back((*it)->elem);
    }

    return is_sorted(order.begin(),order.end());

}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    std::vector<T> order;
    std::vector<T>& trav = order;
    
    _inOrder(root,trav);
    
    return is_sorted(order.begin(),order.end());

}

template <typename T>
void BinaryTree<T>::_inOrder(BinaryTree::Node* subRoot, std::vector<T>& treeVector)const{
    if(subRoot != NULL){
      _inOrder(subRoot->left, treeVector);
      treeVector.push_back(subRoot->elem);
      _inOrder(subRoot->right, treeVector);
    }
}

/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here
    std::vector<T> singlePath;
    _getPaths(root,paths,singlePath);

}

template <typename T>
void BinaryTree<T>::_getPaths(Node * subRoot, std::vector<std::vector<T>>& paths, std::vector<T> singlePath) const
{
    // your code here
    if(subRoot==NULL){
        return;
    }
    singlePath.push_back(subRoot->elem);
    _getPaths(subRoot->left,paths,singlePath);
    if(subRoot->left==NULL && subRoot->right==NULL){
        //copy over existing path then add new nodes
        paths.push_back(singlePath);
    }
    _getPaths(subRoot->right,paths,singlePath);
    singlePath.pop_back();
}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    std::vector<std::vector<T> > v;
    getPaths(v);
    int distance = 0;
    for(size_t i=0; i<v.size(); i++){
      for(size_t j=0; j<v[i].size(); j++){
        distance++;
      }
      
    }
    return distance-2;
}

