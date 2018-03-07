//
//  Controller.cpp
//  DataStructures
//
//  Created by Lamb, Isaac on 1/31/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start() {
//    ArrayTester arrayTest;
//    arrayTest.testArrayUse();
//    arrayTest.testAdvancedArray();
//
//    Timer codeTimer;
//    codeTimer.startTimer();
//    cout << "Look code on the screen" << endl;
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();
//    codeTimer.resetTimer();
//    codeTimer.startTimer();
//    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ilam9372/XCode Projects/DataStructures/DataStructures/Data/crime.csv");
//    for (int i = 200; i < 216; i++) {
//        cout << i << " is " << myData[i] << endl;
//    }
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();
//    findMaxAndMin();
    RecursionTester test;
    test.testRecursionNumbers();
    test.testRecursionString();
}

void Controller :: findMaxAndMin() {
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ilam9372/XCode Projects/DataStructures/DataStructures/Data/crime.csv");
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < myData.size(); i++) {
        if (myData [minIndex] > myData [i]) {
            minIndex = i;
        }
        if (myData [maxIndex] < myData[i])
            maxIndex = i;
    }
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.stopTimer();
    searchTimer.displayInformation();
}
