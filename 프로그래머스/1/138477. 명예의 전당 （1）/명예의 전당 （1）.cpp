#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> honors;

int weeks(int& score, bool flg)
{
    honors.push(-1 * score);
    
    if (flg)
    {
        honors.pop();
    }
    
    return -1 * honors.top();
}


vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    for (auto& sc : score)
    {
        int lastHonor;
        if (honors.size() < k)
        {
            lastHonor = weeks(sc, false);
        }
        else
        {
            lastHonor = weeks(sc, true);
        }
        answer.push_back(lastHonor);
    }
    
    return answer;
}