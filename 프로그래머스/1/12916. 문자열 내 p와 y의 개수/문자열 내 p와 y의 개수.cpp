#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int cnt1=0,cnt2=0;
    for (char c: s) {
        if (c == 'p' || c=='P') cnt1++;
        else if (c == 'y' || c == 'Y') cnt2++;
    }
    

    return cnt1==cnt2;
}