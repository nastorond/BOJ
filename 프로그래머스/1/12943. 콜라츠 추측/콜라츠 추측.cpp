#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long long number = (long long) num;
    
    if (num == 1) return 0;
    
    while (answer < 500) {
        answer++;
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number *= 3;
            number ++;
        }
        if (number == 1) return answer; 
    }
    
    return -1;
}