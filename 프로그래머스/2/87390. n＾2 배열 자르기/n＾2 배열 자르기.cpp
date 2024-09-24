#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; ++i) {
        // i 번째 값을 2D 배열에서 찾는 방식 (행과 열을 계산)
        int row = i / n;
        int col = i % n;

        // 각 위치에서의 값은 max(row, col) + 1
        answer.push_back(max(row, col) + 1);
    }
    
    return answer;
}