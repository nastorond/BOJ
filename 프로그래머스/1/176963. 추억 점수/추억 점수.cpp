#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> scores;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (int i=0; i<name.size(); ++i)
    {
        scores[name[i]] = yearning[i];
    }
    
    for (auto& vt : photo)
    {
        int res=0;
        for (auto& str : vt)
        {
            if (scores.find(str) != scores.end())
            {
                res += scores[str];
            }
        }
        answer.push_back(res);
    }
    
    return answer;
}