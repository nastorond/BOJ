#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int lim = phone_number.size();
    
    for (int i=0; i<lim; i++) {
        if (i < lim-4) {
            answer += '*';
        }
        else {
            answer += phone_number[i];
        }
    }
    
    return answer;
}