#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c: s) {
        if (c == ' ') {
            answer+= c;
            continue;
        }
        
        if (c <= 'Z') {
            c = c + n > 'Z' ? ((c+n)%('Z') - 1) + 'A' : c+n;
        } else {
            c = c + n > 'z' ? ((c+n)%('z') - 1) + 'a' : c+n;
        }
        answer += c;
        
    }
    
    return answer;
}