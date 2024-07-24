#include <string>
#include <vector>
#include <cctype>

using namespace std;

int answer_sheet(string s) {
    if (s == "zero") return 0;
    else if (s == "one") return 1;
    else if (s == "two") return 2;
    else if (s == "three") return 3;
    else if (s == "four") return 4;
    else if (s == "five") return 5;
    else if (s == "six") return 6;
    else if (s == "seven") return 7;
    else if (s == "eight") return 8;
    else if (s == "nine") return 9;
    else return -1;
}

int solution(string s) {
    string answer = "";
    
    string tmp="";
    for (char c: s) {
        if (isdigit(c)) {
            answer += c;
            continue;
        }
        tmp += c;
        if (tmp.size() > 2) {
            int ck = answer_sheet(tmp);
            if (ck > -1) {
                tmp = "";
                answer += '0' + ck;
            }
        }
    }
    
    int res = stoi(answer);
    
    return res;
}