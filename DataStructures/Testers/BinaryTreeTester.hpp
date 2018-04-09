//
//  BinaryTreeTester.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/27/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/Structures/NonLinear/BinarySearchTree.hpp"
#include <iostream>

class BinaryTreeTester {
private:
    BinaryTreeNode<int> testNode;
    BinarySearchTree<int> testTree;
public:
    void testBinaryTree();
};

#endif /* BinaryTreeTester_hpp */
