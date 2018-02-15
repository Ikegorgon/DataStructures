//
//  FileController.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 1/31/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "CrimeData.hpp"
#include "../Model/Structures/LinkedList.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class FileController {
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static LinkedList<CrimeData> readDataToList(string fileName);
};

#endif /* FileController_hpp */
