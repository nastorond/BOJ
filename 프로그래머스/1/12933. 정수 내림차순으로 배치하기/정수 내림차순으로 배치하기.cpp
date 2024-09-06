#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> numCnt(10, 0);
    
    while (n>0) {
        numCnt[n%10]++;
        n /= 10;
    }
    
    for (int i=9; i>=0; i--) {
        while (numCnt[i] > 0) {
            answer *= 10;
            answer += i;
            numCnt[i]--;
        }
    }
    
    return answer;
}