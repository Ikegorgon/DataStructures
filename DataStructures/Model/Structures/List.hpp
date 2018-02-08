//
//  List.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 2/8/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <assert.h>
#include "../Nodes/LinearNode.hpp"

using namespace std;

class List {
protected:
    int size;
public:
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(Type item) = 0;
    virtual Type getFromIndex(int index) = 0;
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
};

#endif /* List_hpp */
