//
//  main.cpp
//  Lab_2
//
//  Created by Елизавета Шимкович on 7.05.23.
//

#include "../include/average_worker.h"
#include "../include/min_max_worker.h"
#include <iostream>
#include <vector>
#include <boost/thread.hpp>

using namespace std;

int RandValue(int min, int max) {
    int range = max - min;
    return min + rand() % range;
}

void PrintArray(vector<int>& data) {
    int size = data.size();
    for(int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
 
int main(int argc, const char * argv[]) {
    int size, min, max;
    std::cout << "Enter array size: ";
    std::cin >> size;
    std::cout << "Enter min: ";
    std::cin >> min;
    std::cout << "Enter max: ";
    std::cin >> max;
    vector<int> data(size);
    for(int i = 0; i < size; i++) {
        data[i] = RandValue(min, max);
    }
    cout << "Initialized array: ";
    PrintArray(data);
    double average = 0.0;
    boost::thread average_worker(AverageWorker, boost::ref(data), boost::ref(average));
    average_worker.join();
    int min_pos = -1;
    int max_pos = -1;
    boost::thread min_max_worker(MinMaxWorker, boost::ref(data), boost::ref(min_pos), boost::ref(max_pos));
    min_max_worker.join();
    data[min_pos] = floor(average);
    data[max_pos] = floor(average);
    cout << "Processed array: ";
    PrintArray(data);
    return 0;
}
