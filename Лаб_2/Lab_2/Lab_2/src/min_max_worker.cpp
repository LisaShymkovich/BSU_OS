//
//  min_max_worker.cpp
//  Lab_2
//
//  Created by Елизавета Шимкович on 7.05.23.
//

#include "../include/min_max_worker.h"
#include <iostream>

int FindMinPos(vector<int>& data) {
    int size = data.size();
    int position = 0;
    int min = data[position];
    for(int i = 1; i < size; i++) {
        int element = data[i];
        if(element < min) {
            min = element;
            position = i;
        }
    }
    return position;
}

int FindMaxPos(vector<int>& data) {
    int size = data.size();
    int position = 0;
    int max = data[position];
    for(int i = 1; i < size; i++) {
        int element = data[i];
        if(element > max) {
            max = element;
            position = i;
        }
    }
    return position;
}

void MinMaxWorker(vector<int>& data, int& min_pos, int& max_pos) {
    min_pos = FindMinPos(data);
    max_pos = FindMaxPos(data);
    cout << "Min: " << data[min_pos] << ", Max: " << data[max_pos] << endl;
}
