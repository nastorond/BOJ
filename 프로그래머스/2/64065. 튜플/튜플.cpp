#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<bool> ck(100001, false);
    vector<vector<int>> tmp;
    vector<int> insertVetor;
    string num = "";
    bool inSet = false;
    
    for(char c : s) {
        if (c == '{') continue;
        if (c == ',') {
            if (num.size() == 0) continue;
            insertVetor.push_back(stoi(num));
            num = "";
        }
        else if (c == '}') {
            if (num.size() == 0) continue;
            insertVetor.push_back(stoi(num));
            num = "";
            tmp.push_back(insertVetor);
            insertVetor.clear();
        } else {
            num += c;
        }
    }
    
    sort(tmp.begin(), tmp.end(), compare);
    
    for (int i=0; i<tmp.size(); i++) {
        for (int num : tmp[i]) {
            if (ck[num]) continue;
            answer.push_back(num);
            ck[num] = true;
        }
    }
    
    return answer;
}