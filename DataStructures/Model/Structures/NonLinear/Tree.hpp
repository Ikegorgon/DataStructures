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
public:
    BinaryTreeNode<Type> root;
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    void insert(Type);
    bool contains(Type);
    void remove(Type);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

template<class Type>
int Tree :: getSize() {
    
}

template<class Type>
int Tree :: getHeight() {
    
}

template<class Type>
bool Tree :: isComplete() {
    
}

template<class Type>
bool Tree :: isBalanced() {
    
}

template<class Type>
void Tree :: insert(Type) {
    
}

template<class Type>
bool Tree :: contains(Type) {
    
}

template<class Type>
void Tree :: remove(Type) {
    
}

template<class Type>
void Tree :: inOrderTraversal() {
    
}

template<class Type>
void Tree :: preOrderTraversal() {
    
}

template<class Type>
void Tree :: postOrderTraversal() {
    
}

#endif /* Tree_hpp */
