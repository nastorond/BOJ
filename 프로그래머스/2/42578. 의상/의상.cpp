#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> counting;
    for (auto v: clothes) {
        if (counting[v[1]] == 0) {
            counting[v[1]] = 0;
        }
        counting[v[1]]++;
    }
    
    for (auto pa : counting) {
        answer *= (pa.second+1);
    }

    return answer-1;
}