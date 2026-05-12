/*
단순 구현
1초부터 전부 세면서 하나하나 구하기
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct stSign
{
    int g, y, r;
    int sumTime;
    
    stSign(int a, int b, int c) : g(a), y(b), r(c), sumTime(a+b+c) {}
};

vector<stSign> signs;
vector<bool> isAvail;

bool isT()
{
    int res = 0;
    for (auto bo : isAvail)
    {
        res += bo ? 1 : 0;
    }
    
    return (res == isAvail.size());
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    size_t maxtime=1;
    for (auto& vt : signals)
    {
        stSign tmp(vt[0], vt[1], vt[2]);
        signs.push_back(tmp);
        //! 최대값 설정
        maxtime *= (vt[0] + vt[1] + vt[2]);
    }
    isAvail.resize(signals.size(), false);
    
    int cur_time = 1;
    while(cur_time <= maxtime)
    {
        bool isY = false;
        
        int idx=0;
        for (auto& si : signs)
        {
            int cur = cur_time%si.sumTime;
            
            if (cur > 0 && cur <= si.g) isAvail[idx] = false;
            else if (cur > si.g && cur <= si.g+si.y) isAvail[idx] = true;
            else isAvail[idx] = false;
            
            //std::cout << cur << " " << isAvail[idx] << " ";
            ++idx;
        }
        //std::cout << "\n";
        
        if (isT())
        {
            answer = cur_time;
            break;
        }
        
        ++cur_time;
    }
    
    return answer;
}