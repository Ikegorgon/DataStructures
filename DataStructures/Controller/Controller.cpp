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
    for (int i = 0; i < 10000; i++) {
        cout << "Index is " << i;
    }
    cout << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
