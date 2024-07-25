#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sol(string s, int len) {
    string tmp = "", res = "", tmp2 = "";
    int cnt = 1;
    
    for (int i=0; i<s.size(); i++) {
        if (tmp.size() < len) tmp += s[i];
        else {
            if (tmp2.size() < len) tmp2 += s[i];
            else {
                if (tmp2 == tmp) {
                    cnt++;
                    tmp2 = s[i];
                } else {
                    if (cnt > 1) {
                        res += to_string(cnt);
                    }
                    res += tmp;
                    tmp = tmp2;
                    tmp2 = s[i];
                    cnt = 1;
                }
            }
        }
    }
    
    if (tmp2 == tmp) {
        cnt++;
        res += to_string(cnt);
        tmp2 = "";
    } else {
        if (cnt > 1) {
            res += to_string(cnt);
        }
    }
    res += tmp;
    if (tmp2.size() <= len) res += tmp2;
    
    // cout << res << "\n";
    
    return res.size();
}

int solution(string s) {
    int answer = 1e9;
    
    // 무조건 앞에서 부터 정해진 길이만큼 잘라서 압축해야 함
    // 절반정도만 확인하면 문제없을듯
    int tmp;
    if (s.size() == 1) return 1;
    for (int i=1; i<s.size()/2 + 1; i++) {
        tmp = sol(s, i);
        answer = min(tmp, answer);
    }
    
    return answer;
}