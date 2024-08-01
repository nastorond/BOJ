#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    string tmpA = to_string(a), tmpB = to_string(b);
    // if (tmpA[0] != tmpB[0] && tmpA[0] > tmpB[0]) return true;
    // else {
    //     if (tmpA.size() == 1 && tmpA[0] < tmpB[1]) return true;
    //     if (tmpB.size() == 1 && tmpB[0] < tmpA[1]) return true;
    // }
    if (tmpA+tmpB > tmpB+tmpA) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // 내림차순으로 정렬, 맨 앞자리가 가장 큰수
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0) return "0";
    
    for (auto it=numbers.begin(); it!=numbers.end(); it++) {
        // cout << *it << " ";
        answer += to_string(*it);
    }
    
    return answer;
}