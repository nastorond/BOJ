#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int tmp = n;
    while (n > 2) {
            n -= 2;
            answer += "수박";
        }
    
    if (tmp%2 == 1) {
        answer += "수";
    }
    else {
        answer += "수박";
    }
    
    return answer;
}