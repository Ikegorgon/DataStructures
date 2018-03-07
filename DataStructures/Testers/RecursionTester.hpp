//
//  RecursionTester.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/5/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef RecursionTester_hpp
#define RecursionTester_hpp

#include <iostream>
#include <string>
#include "../Controller/Tools/Timer.hpp"

using namespace std;

class RecursionTester {
private:
    int fib(int start);
    string mystery(string word);
public:
    void testRecursionNumbers();
    void testRecursionString();
};

#endif /* RecursionTester_hpp */
