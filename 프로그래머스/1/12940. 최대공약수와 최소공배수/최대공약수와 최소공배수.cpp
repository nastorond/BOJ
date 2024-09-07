#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    answer.push_back(n*m/answer[0]);
    
    return answer;
}