//
//  min_max_worker.h
//  Lab_2
//
//  Created by Елизавета Шимкович on 7.05.23.
//

#ifndef min_max_worker_h
#define min_max_worker_h

#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> int_pair;

int FindMinPos(vector<int>& data);
int FindMaxPos(vector<int>& data);
void MinMaxWorker(vector<int>& data, int& min_pos, int& max_pos);

#endif /* min_max_worker_h */
