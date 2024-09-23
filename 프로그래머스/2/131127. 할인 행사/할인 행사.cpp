#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> mapping;
    
    for (int i=0; i<want.size(); i++) {
        mapping[want[i]] = i;
    }
    
    vector<int> cnts(want.size(), 0);
    bool flg = true;
    
    for (int i=0; i<10; i++) {
        if (mapping.find(discount[i]) != mapping.end()) {
            cnts[mapping[discount[i]]]++;
        }
    }
    for (int i=0; i<want.size(); i++) {
        if (number[i] != cnts[i]) {
            flg=false;
            break;
        }
    }
    if (flg) answer++;
    
    for (int i=10; i<discount.size(); i++) {
        if (mapping.find(discount[i-10]) != mapping.end()) {
            cnts[mapping[discount[i-10]]]--;
        }
        if (mapping.find(discount[i]) != mapping.end()) {
            cnts[mapping[discount[i]]]++;
        }
        flg = true;
        for (int i=0; i<want.size(); i++) {
            if (number[i] != cnts[i]) {
                flg=false;
                break;
            }
        }
        if (flg) answer++;
    }
    
    return answer;
}