#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1) return {-1};
    
    int tmp=1e9, idx;
    for (int i=0; i<arr.size(); i++) {
        tmp = min(tmp, arr[i]);
        if (tmp == arr[i]) idx=i;
    }
    arr.erase(arr.begin()+idx);
    
    return arr;
}