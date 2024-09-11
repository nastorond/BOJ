#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    string tmp="";
    for (char c: t) {
        tmp += c;
        if (tmp.size() == p.size()) {
            if (stoll(tmp) <= stoll(p)) answer++;
            
            if (p.size() == 1) tmp = "";
            else tmp = tmp.substr(1);
        }
    }
    
    return answer;
}