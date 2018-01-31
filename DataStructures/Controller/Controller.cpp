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
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Look code on the screen" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ilam9372/XCode Projects/DataStructures/DataStructures/Data/crime.csv");
    for (int i = 234; i < 400; i += 30) {
        cout << i << " is " << myData[i] << endl;
    }
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
