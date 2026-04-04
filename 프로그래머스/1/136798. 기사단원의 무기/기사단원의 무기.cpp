#include <string>
#include <vector>

/*
각 기사 번호 부여 1 ~ N
자신의 번호의 약수 개수에 해당하는 공격력을 가지는 무기 구매예정
    구매 가능한 공격력 제한 있음.
    제한보다 큰 공격력의 무기를 구매하려는 기사는 제한량만큼만 구매해야함.
    
    15 - 1, 3, 5, 15  4개 - 공격력 4인 무기 구매
        협약 : 3 / 제한수치를 초과한 기사가 사용할 무기의 공격력 : 2
        공격력 2인 무기 구매
    
    공격력 당 1kg 의 철 필요
    
약수 개수를 구해야함. 
number 가 5인 경우, 1 ~ 5 약수의 개수를 구해야함.
number == 100,000
n*logn
number 개수만큼 반복 * 개당 logn 만큼 반복

약수 개수 어캐 구하더라..
약수의 개수는 자연수를 기반으로 하니까 1부터 나눴을 때 0이 되는지 점검.
    제곱근인 경우까지만 고려하면 됨. 어차피 그 이상은 그 전의 정보로 추론 가능.
    숫자가 필요하면 숫자를 저장
*/

using namespace std;

int getCount(int n, int limit, int pow)
{
    if (n == 1) return 1;   //! 1인 경우 약수의 개수는 한개
    if (n < 4) return 2;    //! 제곱근이 자연수가 아닌 경우 약수의 개수 두개
    
    int res = 0;
    //! 1부터 순회하며 약수 카운트
    for (int i=1; i*i<=n; ++i)
    {
        //! 값이 제한사항을 넘었을 경우 지정값 리턴
        if (res > limit)
        {
            return pow;
        }
        
        //! 현재 i가 n의 약수인 경우
        if (n%i == 0)
        {
            //! 제곱근은 +1
            if (i*i == n) ++res;
            else 
            {
                //! 약수는 쌍으로 있으므로 2씩 카운트
                res += 2;
            }
        }
    }
    
    //! 값이 제한사항을 넘었을 경우 지정값 리턴
    if (res > limit)
    {
        res = pow;
    }
    
    return res;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int night=1; night<=number; ++night)
    {
        answer += getCount(night, limit, power);
    }
    
    return answer;
}