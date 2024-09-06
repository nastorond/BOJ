#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string tmp = to_string(n);
    
    for (char c : tmp) {
        answer += c - '0';
    }
    
    return answer;
}