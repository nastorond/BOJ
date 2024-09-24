#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkIsAvail(vector<char> s) {
    stack<char> checking;
    
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            checking.push(c);
        } 
        else {
            if (checking.empty()) return false;
            char top = checking.top();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                checking.pop();
            } else {
                return false;
            }
        }
    }
    return checking.empty();
}

int solution(string s) {
    int answer = 0;
    if (s.size() == 1) return 0;
    vector<char> busket;
    for (char c: s) busket.push_back(c);
    
    for (int i=0; i<s.size(); i++) {
        if (checkIsAvail(busket)) answer++;
        vector<char> tmp(busket.begin()+1, busket.end());
        tmp.push_back(busket[0]);
        busket = tmp;
    }
    
    return answer;
}