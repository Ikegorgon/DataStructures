//
//  TestingStacksAndQueues.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 2/26/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef TestingStacksAndQueues_hpp
#define TestingStacksAndQueues_hpp

#include "Timer.hpp"
#include "FileController.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "List.hpp"
#include <iostream>

using namespace std;

class TestingStacksAndQueues {
public:
    void stackVersusList();
    void stackVersusQueue();
    void queueVersusList();
};

#endif /* TestingStacksAndQueues_hpp */
