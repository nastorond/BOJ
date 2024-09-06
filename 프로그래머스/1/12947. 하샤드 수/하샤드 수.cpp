#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int number = x, ck=0;
    
    while (x > 0) {
        ck += x%10;
        x /= 10;
    }
    
    return number%ck == 0;
}