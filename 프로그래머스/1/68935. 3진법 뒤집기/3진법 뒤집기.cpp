#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string tmp="";
    while (n > 0) {
        tmp += to_string(n%3);
        n /= 3;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    for (int i=0; i<tmp.size(); i++) {
        answer += pow(3, i)*(tmp[i]-48);
    }
    
    return answer;
}