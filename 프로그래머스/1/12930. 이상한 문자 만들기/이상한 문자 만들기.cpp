#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt = 0;
    for (char c : s) {
        
        if (c < 'A' ||  c > 'z') {
            answer+= ' ';
            cnt = 0;
            continue;
        }
        
        if(cnt%2 == 0) {
            answer += c >= 'a' ? c - ('a'-'A') : c;
        }
        else {
            answer += c < 'a' ? c + ('a'-'A') : c;
        }
        cnt++;
    }
    
    return answer;
}