#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    unordered_set<int> ret;
    
    for (int i=0; i<numbers.size(); i++) {
        for (int j=0; j<numbers.size(); j++) {
            if (i == j) continue;
            if (ret.count(numbers[i] + numbers[j])) continue;
            ret.insert(numbers[i] + numbers[j]);
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}