using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    count = count * (count+1) / 2;
    long long totalPrice = (long long) price * count;
    
    if (totalPrice > (long long) money) {
        return totalPrice - (long long) money;
    }

    return answer;
}