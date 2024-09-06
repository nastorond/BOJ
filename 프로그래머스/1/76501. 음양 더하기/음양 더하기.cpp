#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0, lim = signs.size();
    
    for (int i=0; i<lim; i++) {
        if (!signs[i]) absolutes[i]*=(-1);
        answer += absolutes[i];
    }
    
    return answer;
}