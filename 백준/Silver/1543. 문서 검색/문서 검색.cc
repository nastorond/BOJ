#include<bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    string doc, keyword, tmp="";
    
    getline(cin, doc);
    getline(cin, keyword);
    
    int cnt=0, lim = keyword.size();
    for (int i=0; i<doc.size(); i++) {
        tmp += doc[i];
        if (tmp.size() == lim) {
            if (tmp == keyword) {
                cnt++;
                tmp="";
            } else {
                tmp = tmp.substr(1, lim-1);
            }
        }
    }
    cout << cnt << "\n";
    
    return 0;
}