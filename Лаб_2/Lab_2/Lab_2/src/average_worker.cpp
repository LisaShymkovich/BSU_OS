//
//  average_worker.cpp
//  Lab_2
//
//  Created by Елизавета Шимкович on 7.05.23.
//

#include "../include/average_worker.h"
#include <iostream>

double FindAverage(vector<int>& data) {
    int size = data.size();
    if(size == 0) return 0;
    int sum = 0;
    for(auto& element : data) {
        sum += element;
    }
    return static_cast<double>(sum) / size;
}

void AverageWorker(vector<int>& data, double& average) {
    average = FindAverage(data);
    cout << "Average: " << average << endl;
}
