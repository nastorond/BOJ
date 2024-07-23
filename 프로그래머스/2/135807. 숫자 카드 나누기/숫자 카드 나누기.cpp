#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcdVal (vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    
    int res = *arr.begin();
    for (auto it = arr.begin()+1; it != arr.end(); it++) {
        res = __gcd(res, *it);
    }
    return res;
}

bool check (int val, vector<int> arr) {
    for (auto it=arr.begin(); it!=arr.end(); it++) {
        if (*it%val == 0) return false;
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) { 
    int gcdA = gcdVal(arrayA);
    int gcdB = gcdVal(arrayB);
    
    cout << gcdA << " " << gcdB << "\n"; 
    
    bool ck1 = check(gcdA, arrayB);
    bool ck2 = check(gcdB, arrayA);
    
    if (ck1 && ck2) return gcdA > gcdB ? gcdA : gcdB;
    if (ck1) return gcdA;
    if (ck2) return gcdB;
    
    return 0;
    
}