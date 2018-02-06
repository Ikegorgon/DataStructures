//
//  Node.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 2/6/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <class Type>
class Node {
protected:
    Type data;
public:
    Node();
    Node(Type data);
    void setData(Type data);
    Type getData();
};
template <class Type>
Node<Type> :: Node() {
    
}
template <class Type>
Node<Type> :: Node(Type data) {
    this->data = data;
}
template <class Type>
void Node<Type> :: setData(Type data) {
    this->data = data;
}
template <class Type>
Type Node<Type> :: getData() {
    return data;
}

#endif /* Node_hpp */
