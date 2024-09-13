#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2, 0);
    
    int numOfZero = 0, num;
    while (s.size() > 1) {
        answer[0]+=1;
        num = 0;
        for (char c: s) {
            if (c =='0') numOfZero++;
            else num++;
        }
        s="";
        while (num > 0) {
            if (num%2) s+='1';
            else s+='0';
            num /= 2;
        }
    }
    answer[1] = numOfZero;  
    return answer;
}