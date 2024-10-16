#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> stMap1, stMap2;
unordered_set<string> checkingSet;

bool condition(char a, char b) {
    return a < 'a' || a > 'z' || b < 'a' || b > 'z';
}

void preProcessing (string& str1, string& str2, vector<string>& st1, vector<string>& st2) {
    string tmp = "";
    
    for (char c: str1) tmp += tolower(c);
    str1 = tmp; tmp = "";
    
    for (char c: str2) tmp += tolower(c);
    str2 = tmp; tmp = "";
    
    for (int i=1; i<str1.size(); i++) {
        if (condition(str1[i-1], str1[i])) continue;
        tmp = "";
        tmp += str1[i-1];
        tmp += str1[i];
        st1.push_back(tmp);
        stMap1[tmp]++;
        checkingSet.insert(tmp);
    }
    for (int i=1; i<str2.size(); i++) {
        if (condition(str2[i-1], str2[i])) continue;
        tmp = "";
        tmp += str2[i-1];
        tmp += str2[i];
        st2.push_back(tmp);
        stMap2[tmp]++;
        checkingSet.insert(tmp);
    }
    
    return ;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> st1, st2;
    preProcessing(str1, str2, st1, st2);
    
    int jakad1=0, jakad2=0;
    for (string tmp : checkingSet) {
        jakad1 += min(stMap1[tmp], stMap2[tmp]);
        jakad2 += max(stMap1[tmp], stMap2[tmp]);
    }
    
    if (jakad2 == 0) return 65536;
    return static_cast<int>((static_cast<double>(jakad1) / jakad2) * 65536);
}