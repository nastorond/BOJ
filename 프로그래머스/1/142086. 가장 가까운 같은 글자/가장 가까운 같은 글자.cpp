#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> mapping;
    
    for (int i=0; i<s.size(); i++) {
        if (mapping.count(s[i]) == 0) {
            mapping.insert({s[i], i});
            answer.push_back(-1);
        } else {
            answer.push_back(i - mapping[s[i]]);
            mapping[s[i]] = i;
        }
    }
    
    return answer;
}