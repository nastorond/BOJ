#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    long long tmp = pow(n, 0.5);
    if (pow(tmp, 2) == n) return pow(tmp+1, 2);
    
    return answer;
}