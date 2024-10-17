#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    vector<bool> ck(21, false);
    unordered_set<string> ckSet;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for(string s : phone_book) {
        string tmp = "";
        for (char c : s) {
            tmp += c;
            if (!ck[tmp.size()]) continue;
            if (ckSet.count(tmp) > 0) return false;
        }
        
        if (!ck[s.size()]) {
            ckSet.insert(s);
            ck[s.size()] = true;
        }
        else {
            ckSet.insert(s);
        }
    }
    
    return true;
}