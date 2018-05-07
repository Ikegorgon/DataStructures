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
    if (node != nullptr) {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> *current) {
    BinaryTreeNode<Type> * currentNode = current;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr) {
        previous = currentNode;
        currentNode = currentNode->getRight();
    }
    return previous;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> *current) {
    BinaryTreeNode<Type> * currentNode = current;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr) {
        previous = currentNode;
        currentNode = currentNode->getLeft();
    }
    return previous;
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> *removeMe) {
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    previous = removeMe->getRoot();
    if (removeMe->getRight() == nullptr && removeMe->getLeft() == nullptr) {
        temp = removeMe;
        removeMe = nullptr;
        if (previous != nullptr && removeMe->getData() < previous->getData()) {
            previous->setLeftNode(removeMe);
        } else if (previous != nullptr && removeMe->getData() > previous->getData()) {
            previous->setRightNode(removeMe);
        }
        delete temp;
    } else if (removeMe->getRight() == nullptr) {
        temp = removeMe;
        removeMe = removeMe->getLeft();
        if (previous != nullptr && temp->getData() < previous->getData()) {
            previous->setLeftNode(removeMe);
        } else if (previous != nullptr && temp->getData() > previous->getData()) {
            previous->setRightNode(removeMe);
        }
        delete temp;
    } else if (removeMe->getLeft() == nullptr) {
        temp = removeMe;
        removeMe = removeMe->getRight();
        if (previous != nullptr && removeMe->getData() < previous->getData()) {
            previous->setLeftNode(removeMe);
        } else if (previous != nullptr && removeMe->getData() > previous->getData()) {
            previous->setRightNode(removeMe);
        }
        removeMe->setRightNode(removeMe);
        delete temp;
    } else {
        current = getRightMostChild(removeMe->getLeft());
        previous = current->getRoot();
        removeMe->setData(current->getData());
        if (previous == nullptr) {
            removeMe->setLeftNode(current->getLeft());
        } else {
            previous->setRightNode(current->getLeft());
        }
        if (current->getLeft() != nullptr) {
            current->getLeft()->setRootNode(removeMe);
        }
        delete current;
    }
    if (removeMe == nullptr || removeMe->getRoot() == nullptr) {
        this->root = removeMe;
    }
}

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() {
    
}

template <class Type>
BinarySearchTree<Type>  :: ~BinarySearchTree() {
    destroyTree(this->root);
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
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr) {
        return false;
    } else {
        while (current != nullptr) {
            if (value == current->getData()) {
                return true;
            } else if (value < current->getData()) {
                current = current->getLeft();
            } else {
                current = current->getRight();
            }
        }
        return false;
    }
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
    if (this->root == nullptr) {
        cout << "Empty tree so removal is not possible" << endl;
    } else {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        while (current != nullptr && !hasBeenFound) {
            if (current->getData() == value) {
                hasBeenFound = true;
            } else {
                previous = current;
                if(value < current->getData()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }
            }
        }
        if (current == nullptr) {
            cerr << "Item not found, removal unsuccessful" << endl;
        } else if (hasBeenFound) {
            if (current == this->root) {
                removeNode(this->root);
            } else if (value < previous->getData()) {
                removNode(previous->getLeft());
            } else {
                removeNode(previous->getRight());
            }
        }
    }
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum() {
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData;
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum() {
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
}

#endif /* BinarySearchTree_hpp */
