//
//  BinaryTreeNode.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/27/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <stdio.h>
#include "Node.hpp"

template<class Type>
public class BinaryTreeNode() {
protected:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * left;
    BinaryTreeNode<Type> * right;
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    BinaryTreeNode<Type> * getRoot();
    BinaryTreeNode<Type> * getLeft();
    BinaryTreeNode<Type> * getRight();
    void setRootNode(BinaryTreeNode<Type> * root);
    void setLeftNode(BinaryTreeNode<Type> * left);
    void setRightNode(BinaryTreeNode<Type> * right);
};

template<class Type>
BinaryTreeNode<Type> :: BinBinaryTreeNode() : Node<Type>() {
    this->root = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template<class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node<Type>(data) {
    this->root = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template<class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRoot() {
    return root;
}

template<class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeft() {
    return left;
}

template<class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRight() {
    return right;
}

template<class Type>
void BinaryTreeNode<Type> :: setRootNode(BinaryTreeNode<Type> * root) {
    this->root = root;
}

template<class Type>
void BinaryTreeNode<Type> :: setLeftNode(BinaryTreeNode<Type> * left) {
    this->left = left;
}

template<class Type>
void BinaryTreeNode<Type> :: setRightNode(BinaryTreeNode<Type> * right) {
    this->right = right;
}

#endif /* BinaryTreeNode_hpp */
