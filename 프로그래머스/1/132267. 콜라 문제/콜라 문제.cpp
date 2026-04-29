#include <string>
#include <vector>

using namespace std;

//vector<int> saveB;

// //! a개 병 -> b개 병으로 교환, cur : 현재 남은 병 수
// int cal(int a, int b, int cur)
// {
//     if (saveB[cur] != -1)
//     {
//         return saveB[cur];
//     }
    
//     int convCnt = cur/a; //! 교환 가능 횟수
    
//     if (cur%a < 2 && convCnt > 0) //! 남은 병의 수가 2개 미만일 경우 이후 추가 교환 불가
//     {
//         --convCnt; //! 교환 횟수 감소
//     }
    
//     int convB = convCnt * b; //! 교환한 병의 개수
    
//     //! 현재 병 수 - 교환하는데 사용한 병 수 + 교환받은 병 수 = 현재 병의 수로 교환하고 남은 병의 개수
//     int curRes = cur - (convCnt * a) + convB;
    
//     if (curRes < a || curRes < 2) //! 추가 교환이 불가능한 경우
//     {
//         saveB[cur] = convB;
//     }
//     else
//     {
//         //! 추가 교환 진행
//         saveB[cur] = cal(a, b, curRes) + convB;
//     }
    
//     return saveB[cur];
// }

int solution(int a, int b, int n) {
    int answer = 0;
    
    //answer = cal(a, b, n);
    
    while (true)
    {
        int cnt = n/a;
        if (cnt == 0) break;
        answer += (cnt * b);
        n = n - (cnt * a) + (cnt * b);
    }
    
    return answer;
}