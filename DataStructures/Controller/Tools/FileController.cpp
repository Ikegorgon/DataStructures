//
//  FileController.cpp
//  DataStructures
//
//  Created by Lamb, Isaac on 1/31/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#include "FileController.hpp"

vector<CrimeData> FileController :: readCrimeDataToVector(string filename) {
    std :: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    ifstream dataFile(filename);
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            getline(dataFile, currentCSVLine, '\r');
            if (rowCount != 0) {
                CrimeData row(currentCSVLine);
                crimeVector.push_back(row);
            }
            rowCount++;
        }
        dataFile.close();
    } else {
        cerr << "NO FILE" << endl;
    }
    return crimeVector;
}
