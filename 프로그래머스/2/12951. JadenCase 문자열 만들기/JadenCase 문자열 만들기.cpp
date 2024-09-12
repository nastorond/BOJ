#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flg = true;

    for (char c: s) {
        if (c == ' ') {
            flg = true;
        } else if (flg) {
            c = ('a' <= c && c <= 'z') ? c - ('a'-'A') : c;
            flg = false;
        } else {
            c = ('A' <= c && c <= 'Z') ? c + ('a'-'A') : c;
        }
        answer += c;
    }
    
    return answer;
}