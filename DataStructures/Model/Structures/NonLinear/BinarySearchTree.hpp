//
//  BinarySearchTree.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/29/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type> {
protected:
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    void destroyTree(BinaryTreeNode<Type> * node);
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    void removeNode(BinaryTreeNode<Type> * removeMe);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinaryTreeNode<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * root);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * start);
    void demo();
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * startNode) {
    if (startNode != nullptr) {
        return calculateSize(startNode->getLeft()) + calculateSize(startNode->getRight()) + 1;
    }
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> *startNode) {
    if (startNode != nullptr) {
        return max(calculateHeight(startNode->getLeft()), calculateHeight(startNode->getRight())) + 1;
    }
    return 0;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> *startNode) {
    int leftHeight = 0;
    int rightHeight = 0;
    if (startNode == nullptr) {
        return true;
    }
    leftHeight = calculateHeight(startNode->getLeft());
    rightHeight = calculateHeight(startNode->getRight());
    int heightDifferent = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(startNode->getLeft());
    bool rightBalanced = isBalanced(startNode->getRight());
    if (heightDifferent <= 1 && leftBalanced && rightBalanced) {
        return true;
    }
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> *startNode, int index, int size) {
    if (startNode == nullptr) {
        return true;
    }
    if (index >= size) {
        return false;
    }
    return (isComplete(startNode->getLeft(), 2 * index + 1, size) && isComplete(startNode->getRight(), 2 * index + 1, size));
}

template <class Type>
void BinarySearchTree<Type>  :: inOrderTraversal(BinaryTreeNode<Type> *inStart) {
    if(inStart != nullptr) {
        inOrderTraversal(inStart->getLeft());
        cout << inStart->getData() << endl;
        inOrderTraversal(inStart->getRight());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> *preStart) {
    if(preStart != nullptr) {
        cout << preStart->getData() << endl;
        preOrderTraversal(preStart->getLeft());
        preOrderTraversal(preStart->getRight());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> *postStart) {
    if (postStart != nullptr) {
        postOrderTraversal(postStart->getLeft());
        postOrderTraversal(postStart->getRight());
        cout << postStart->getData() << endl;
    }
}

template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> *node) {
    
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> *current) {
    return nullptr;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> *current) {
    return nullptr;
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> *removeMe) {
    
}

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() {
    
}

template <class Type>
BinarySearchTree<Type>  :: ~BinarySearchTree() {
    
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRoot() {
    
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinaryTreeNode<Type> *root) {
    
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal() {
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal() {
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal() {
    postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps(BinaryTreeNode<Type> * start) {
    if (start != nullptr) {
        cout << "Check if left is here" << endl;
        demoTraversalSteps(start->getLeft());
        cout << "At root" << endl;
        cout << "Check if right is here" << endl;
        demoTraversalSteps(start->getRight());
    } else {
        cout << "Reached nullptr - if on right it's back up the recursive call stack" << endl;
    }
}

template <class Type>
void BinarySearchTree<Type> :: demo() {
    demoTraversalSteps(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: getSize() {
    int size = 0;
    size += calculateSize(this->root);
    return size;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight() {
    return -1;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete() {
    int index = 0;
    int size = getSize();
    return isComplete(this->root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced() {
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type value) {
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert) {
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr) {
        this->root = insertMe;
    } else {
        while(current != nullptr) {
            previous = current;
            if(itemToInsert < current->getData()) {
                current = current->getLeft();
            } else if(itemToInsert > current->getData()) {
                current = current->getRight();
            } else {
                cerr << "Item exists already - Exiting inset" << endl;
                delete insertMe;
                return;
            }
        }
        if (previous->getData() > itemToInsert) {
            previous->setLeftNode(insertMe);
        } else {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type value) {
    
}

#endif /* BinarySearchTree_hpp */
