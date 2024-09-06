#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
    return a > b;
}

string solution(string s) {
    string answer = "";
    vector<char> str;
    
    for (char c: s) {
        str.push_back(c);
    }
    sort(str.begin(), str.end(), compare);
    
    for (char c: str) answer += c;    
    
    return answer;
}