//
//  GraphTester.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/23/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef GraphTester_hpp
#define GraphTester_hpp

#include <iostream>
#include "../Model//Structures//NonLinear/Graph.hpp"

class GraphTester {
private:
    Graph<string> puzzle;
    void setup();
    void compareTraversals();
    void findCheapestTraversal();
public:
    void testGraphs();
};

#endif /* GraphTester_hpp */
