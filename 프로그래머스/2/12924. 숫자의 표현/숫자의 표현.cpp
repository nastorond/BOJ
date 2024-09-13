#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, left=1, right=2, cal=left+right;
    
    if (n == 1) return 1;
    
    while (left <= right) {
        if (cal < n) {
            right++;
            cal += right;
        }
        else if (cal > n) {
            cal -= left;
            left++;
        }
        if (cal == n) {
            answer++;
            cal -= left;
            left++;
        }
    }
    
    return answer;
}