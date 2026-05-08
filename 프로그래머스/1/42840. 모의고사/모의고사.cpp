#include <string>
#include <vector>

using namespace std;

int ans(vector<int>& user, vector<int>& answers)
{
    int res=0;
    int idx=1;
    
    for (int& n : answers)
    {
        if (n == user[idx-1])
        {
            ++res;
        }
        ++idx;
        if (idx > user.size()) idx=1;
    }
    
    return res;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> user1 = {1, 2, 3, 4, 5};
    vector<int> user2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> user3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> results;
    
    int maxidx=1; int maxval = 0;
    int res = ans(user1, answers);
    results.push_back(res);
    maxval = res;
    
    res = ans(user2, answers);
    results.push_back(res);
    maxval = maxval < res ? res : maxval;
    
    res = ans(user3, answers);
    results.push_back(res);
    maxval = maxval < res ? res : maxval;
    
    for (int i=0; i<3; ++i)
    {
        if (results[i] == maxval)
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}