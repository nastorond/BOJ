#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int cnt = 0;
    for(int i=0; i<A.size(); i++) {
        if (A[cnt] < B[i]) {
            answer++;
            cnt++;
        }
    }
    
    return answer;
}