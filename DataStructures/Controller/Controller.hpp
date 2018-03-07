//
//  Controller.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 1/31/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "Tools/Timer.hpp"
#include "FileController.hpp"
#include "../Model/Structures/Linear/Array.hpp"
#include "../Testers/ArrayTester.hpp"
#include "../Testers/RecursionTester.hpp"

class Controller {
private:
    void findMaxAndMin();
public:
    void start();
};

#endif /* Controller_hpp */
