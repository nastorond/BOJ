#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), compare);
    int start=targets[0][0], end=targets[0][1], lim=targets.size();
    
    for (int i=1; i<lim; i++) {
        if (targets[i][0] < end) continue;
        else {
            answer++;
            start = targets[i][0];
            end = targets[i][1];
        }
    }
    
    return answer;
}