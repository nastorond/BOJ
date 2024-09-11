#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int tmp, maxNum=-1e9, minNum=1e9;
    string tmpNum;
    for (char c: s) {
        if (c != ' ') tmpNum += c;
        else {
            tmp = stoi(tmpNum);
            maxNum = max(maxNum, tmp);
            minNum = min (minNum, tmp);
            tmpNum = "";
        }
    }
    tmp = stoi(tmpNum);
    maxNum = max(maxNum, tmp);
    minNum = min (minNum, tmp);
    tmpNum = "";
    
    return to_string(minNum) + " " + to_string(maxNum);
}