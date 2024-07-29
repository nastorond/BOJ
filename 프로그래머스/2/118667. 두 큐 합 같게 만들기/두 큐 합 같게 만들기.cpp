#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    long long tmp1=0, tmp2=0;
    for (int i=0; i<queue1.size(); i++) {
        tmp1 += queue1[i];
        tmp2 += queue2[i];
    }
    
    int cnt = 0, lim = queue1.size() * 3;
    int idx1=0, idx2=0;
    while (cnt < lim) {
        if (tmp1 == tmp2) {
            return cnt;
        }
        if (tmp1 > tmp2) {
            int tmp = queue1[idx1];
            tmp1 -= tmp;
            tmp2 += tmp;
            queue2.push_back(tmp);
            idx1++;
        } 
        else if (tmp2 > tmp1) {
            int tmp = queue2[idx2];
            tmp2 -= tmp;
            tmp1 += tmp;
            queue1.push_back(tmp);
            idx2++;
        }
        cnt++;
    }
    
    return answer;
}