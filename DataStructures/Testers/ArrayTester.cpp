//
//  ArrayTester.cpp
//  DataStructures
//
//  Created by Lamb, Isaac on 2/6/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#include "ArrayTester.hpp"

void ArrayTester :: testArrayUse() {
    Array<int> firstArray(10);
    for (int i = 0; i < 10; i++) {
        firstArray.setAtIndex(i, i);
    }
    for (int i = 0; i < firstArray.getsize(); i++) {
        cout << firstArray[i] << endl;
    }
    Array<int> secondArray(400);
    cout << secondArray.getsize() << endl;
    cout << firstArray.getsize() << endl;
    
    Array<int> thirdArray(secondArray);
    
    cout << thirdArray.getsize() << endl;
    firstArray = thirdArray;
    cout << firstArray[4] << endl;
    thirdArray[5] = 123;
    cout << thirdArray[5] << endl;
}

void ArrayTester :: testAdvancedArray() {
    vector<CrimeData> test = FileController :: readCrimeDataToVector("/Users/ilam9372/XCode Projects/DataStructures/DataStructures/Data/crime.csv");
    int arraySize = test.size();
    Array<CrimeData> data(arraySize);
    for (int i = 0; i < arraySize; i++) {
        data[i] = test[i];
    }
    Timer vectorTimer;
    Timer arrayTimer;
    
    vectorTimer.startTimer();
    cout << test[3425] << endl;
    vectorTimer.stopTimer();
    vectorTimer.displayInformation();
    
    arrayTimer.startTimer();
    cout << data[3425] << endl;
    arrayTimer.stopTimer();
    arrayTimer.displayInformation();
}
