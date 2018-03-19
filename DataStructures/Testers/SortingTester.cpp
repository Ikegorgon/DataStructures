//
//  SortingTester.cpp
//  DataStructures
//
//  Created by Lamb, Isaac on 3/15/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#include "SortingTester.hpp"
void sortingTester:: quickSort(vector<CrimeData> & data, int low, int high) {
    if (low < high) {
        int partitionPoint = partition(data, low, high);
        quickSort(data, low, partitionPoint - 1);
        quickSort(data, partitionPoint + 1, high);
    }
}
int sortingTester:: partition(vector<CrimeData> & info, int low, int high) {
    CrimeData pivotValue = info [high];
    int smallest = low - 1;
    for (int i = low; i < high; i++) {
        if (info[i] < pivotValue) {
            smallest++;
            swap(info, smallest, i);
        }
    }
    swap(info, smallest + 1, high);
    return smallest + 1;
}
void sortingTester:: swap(vector<CrimeData> & info, int small, int large) {
    CrimeData temp = info[small];
    info[small] = info[large];
    info[large] = temp;
    swapCount++;
}
void sortingTester:: testSorts() {
    Timer sortTimer;
    swapCount = 0;
    vector<CrimeData> data = FileController::readCrimeDataToVector("/Users/ilam9372/XCode Projects/DataStructures/DataStructures/Data/crime.csv");
    vector<CrimeData> smaller;
    for(int i = 0; i < 100000; i++) {
        smaller.push_back(data[i]);
    }
    sortTimer.startTimer();
    quickSort(smaller, 0, smaller.size());
    sortTimer.stopTimer();
    sortTimer.displayInformation();
    cout << "The number of swaps were: " << swapCount << endl;
}
