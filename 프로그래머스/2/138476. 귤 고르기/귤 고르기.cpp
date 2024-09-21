#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> ck;
    vector<int> cnt;
    
    if (k == 1) return 1;
    
    for (int i : tangerine) {
        ck[i]++;
    }
    for (auto& it : ck) {
        cnt.push_back(it.second);
    }
    sort(cnt.begin(), cnt.end(), [](int a, int b){
        return a > b;
    });
    
    int tmp=0;
    for (int c : cnt) {
        cout << c << " ";
        tmp += c;
        answer++;
        if (tmp >= k) {
            break;
        }
    }
    cout << "\n";
    return answer;
}