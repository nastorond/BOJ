/*
순서대로 n개
각 퍼즐은 소요시간, 난이도 존재
숙련도에 따라 퍼즐 풀 때 틀리는 횟수가 바뀜

time += diff <= level 
    ? 
    time_cur : 
    (diff - level) * (time_cur + time_prev)

limit 존재 limit까지는 ㄱㅊ
level은 변하지 않음
diffs[0] = 1 고정
*/

#include <string>
#include <vector>
#include <iostream>
#define vi vector<int> //! vector<int> 를 vi로 사용
#define ll long long

using namespace std;

bool isAvail(vi& diffs, vi& times, ll limit, ll curLvl)
{
    ll time=0;
    for (int idx=0; idx<diffs.size(); ++idx)
    {
        ll curDiff = diffs[idx];
        ll curTime = times[idx];
        time += curTime; //! 풀이하는데 고정으로 드는 시간
        
        //! 현재 레벨보다 어려우면
        if (curDiff > curLvl)
        {
            time += (curDiff - curLvl)*(curTime + (ll)times[idx-1]);
        }
        
        //! 제한값을 넘기면 실패
        if (time > limit)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    if (diffs.size() == 1) return times[0];
    
    ll maxLvl = 0; //! 최대값 저장
    for (int diff : diffs)
    {
        if (maxLvl < diff)
        {
            maxLvl = static_cast<ll>(diff); //! 최대값으로 갱신
        }
    }

    ll minLvl = 1;
    
    while (minLvl <= maxLvl)
    {
        ll mid = (minLvl + maxLvl) / 2;
        
        if (isAvail(diffs, times, limit, mid))
        {
            maxLvl = mid-1;
            answer = mid;
        }
        else
        {
            minLvl = mid+1;
        }
    }
    
    return answer;
}