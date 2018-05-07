//
//  AVLTree.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 4/17/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type> {
private:
    BinaryTreeNode<Type> * leftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * balancedSubTree (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * insertNode (BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode (BinaryTreeNode<Type> * parent, Type value);
    int heightDifference(BinaryTreeNode<Type> * parent);
public:
    AVLTree();
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
int AVLTree<Type> :: heightDifference (BinaryTreeNode<Type> * node) {
    int balance;
    int leftHeight = this -> calculateHeight(node->getLeft());
    int rightHeight = this -> calculateHeight(node->getRight());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation (BinaryTreeNode<Type> * parent) {
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getLeft();
    parent -> setLeftNode(changedNode->getRight());
    changedNode -> setRightNode(parent);
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation (BinaryTreeNode<Type> * parent) {
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getRight();
    parent -> setRightNode(changedNode->getLeft());
    changedNode -> setLeftNode(parent);
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinaryTreeNode<Type> * parent) {
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getLeft();
    parent -> setLeftNode(rightRotation(changedNode));
    return leftRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinaryTreeNode<Type> * parent) {
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getRight();
    parent -> setRightNode(leftRotation(changedNode));
    return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balancedSubTree (BinaryTreeNode<Type> * parent) {
    int balanceFactor = heightDifference(parent);
    if (balanceFactor > 1) {
        if (heightDifference(parent->getLeft()) > 0) {
            parent = leftRotation(parent);
        } else {
            parent = leftRightRotation(parent);
        }
    } else if (balanceFactor < -1) {
        if (heightDifference(parent -> getRight()) > 0) {
            parent = rightLeftRotation(parent);
        } else {
            parent = rightRotation(parent);
        }
    }
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item) {
    insertNode(this->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item) {
    removeNode(this->getRoot(), item);
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>() {
    this -> root = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted) {
    if (parent == nullptr) {
        return parent;
    }
    if (inserted < parent -> getNodeData()) {
        parent -> setLeftChild(removeNode(parent -> getLeftNode(), inserted));
    } else if (inserted > parent -> getNodeData()) {
        parent -> setRightChild(removeNode(parent -> getRightNode(), inserted));
    } else {
        BinaryTreeNode<Type> * temp;
        if (parent -> getLeftNode() == nullptr && parent -> getRightNode() == nullptr) {
            temp = parent;
            delete temp;
        } else if (parent -> getLeftNode() == nullptr) {
            * parent = * parent -> getRightNode();
        } else if (parent -> getRightNode() == nullptr) {
            * parent = * parent -> getLeftNode();
        } else {
            BinaryTreeNode<Type> * leftMost = this -> getLeftMostChild(parent -> getRightNode());
            parent -> setNodeData(leftMost -> getNodeData());
            parent -> setRightChild(removedNode(parent -> getRightNode(), leftMost -> getNodeData()));
        }
    }
    if (parent == nullptr) {
        return parent;
    }
    return balancedSubTree(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode (BinaryTreeNode<Type> * parent, Type inserted) {
    if (parent == nullptr) {
        parent = new BinaryTreeNode<Type>(inserted);
        return parent;
    } else if (inserted < parent -> getNodeData()) {
        parent -> setLeftChild(insertedNode(parent -> getLeftNode(), inserted));
        parent = balancedSubTree(parent);
    } else if (inserted > parent -> getNodeData()) {
        parent -> setRightChild(insertNode(parent -> getRightNode(), inserted));
        parent = balancedSubTree(parent);
    }
    return parent;
}

#endif /* AVLTree_hpp */
