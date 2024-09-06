#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if (s.size() != 4  && s.size() != 6) return false;
    
    for (char c : s) {
        if ('9' - c + 1 < 0) return false;
    }
    
    return answer;
}