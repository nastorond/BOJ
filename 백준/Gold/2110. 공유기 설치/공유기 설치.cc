/*
Gold 4 공유기설치
수직선 위에 집 N개

특정 개수의 공유기를 N개에 집에 적당히 설치, 가장 인접한 공유기의 거리를 최대로.

1, 2, 4, 8, 9
정렬 - n log n
정렬 후 진행

이분탐색으로 특정 거리를 구하고 그 거리로 모든 집이 커버 가능한지 탐색
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> houses;

int solution()
{
    //! 이분탐색 기반 구현
    int st = 1;
    int ed = houses[n-1] - houses[0];

    int res = 0;
    if (c == 2) return ed; //! 공유기 두개면 가장 양 끝이 최대

    while (st <= ed)
    {
        int mid = (st + ed) / 2;

        int cnt = 1; //! 한개 설치
        int cur = houses[0]; //! 시작점
        for (int h : houses)
        {
            if (h - cur >= mid)
            {
                ++cnt;
                cur = h;
            }
        }

        if (cnt >= c) //! 설치 성공
        {
            res = mid;
            st = mid+1;
        }
        else
        {
            ed = mid-1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> c;

    int loc;
    for (int i=0; i<n; ++i)
    {
        cin >> loc;
        houses.push_back(loc);
    }

    sort(houses.begin(), houses.end());

    cout << solution() << "\n";

    return 0;
}