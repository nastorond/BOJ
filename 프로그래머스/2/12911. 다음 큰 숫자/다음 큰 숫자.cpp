#include <string>
#include <vector>

using namespace std;

int getNumOfOne(int n) {
    int res=0;
    while (n>0) {
        if (n%2) res++;
        n/=2;
    }
    return res;
}

int solution(int n) {
    int answer = 0, ret=0;
    int cnt=getNumOfOne(n);
    
    while (cnt != ret) {
        n += 1;
        ret = getNumOfOne(n);
    }
    
    return n;
}