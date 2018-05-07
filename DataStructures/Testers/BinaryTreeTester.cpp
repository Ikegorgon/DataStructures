//
//  BinaryTreeTester.cpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/27/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester :: testBinaryTree() {
    testTree.insert(3);
    testTree.insert(1);
    testTree.insert(2);
    testTree.insert(-3246000);
    testTree.insert(-12);
    testTree.insert(7);
    testTree.insert(5);
    testTree.insert(6);
    testTree.insert(8);
    testTree.insert(5000);
    testTree.insert(9001);
    testTree.insert(10);
    testTree.insert(600);
//
//    testTree.inOrderTraversal();
//    testTree.preOrderTraversal();
//    testTree.postOrderTraversal();
    testTree2.insert(1);
    testTree.isBalanced();
    testTree.isComplete();
    testTree.getHeight();
}
