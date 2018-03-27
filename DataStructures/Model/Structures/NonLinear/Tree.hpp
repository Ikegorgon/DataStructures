//
//  Tree.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/27/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "../../Node/BinaryTreeNode.hpp"

template<class Type>
class Tree {
protected:
    BinaryTreeNode<Type> * root;
public:
    virtual int getSize() = 0;
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    virtual void insert(Type) = 0;
    virtual bool contains(Type) = 0;
    virtual void remove(Type) = 0;
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
};

//template<class Type>
//int Tree :: getSize() {
//
//}
//
//template<class Type>
//int Tree :: getHeight() {
//
//}
//
//template<class Type>
//bool Tree :: isComplete() {
//
//}
//
//template<class Type>
//bool Tree :: isBalanced() {
//
//}
//
//template<class Type>
//void Tree :: insert(Type) {
//
//}
//
//template<class Type>
//bool Tree :: contains(Type) {
//
//}
//
//template<class Type>
//void Tree :: remove(Type) {
//
//}
//
//template<class Type>
//void Tree :: inOrderTraversal() {
//
//}
//
//template<class Type>
//void Tree :: preOrderTraversal() {
//
//}
//
//template<class Type>
//void Tree :: postOrderTraversal() {
//
//}

#endif /* Tree_hpp */
