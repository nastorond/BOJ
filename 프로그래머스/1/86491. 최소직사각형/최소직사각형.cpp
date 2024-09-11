#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w=0, h=0;
    for (vector<int> v : sizes) {
        if (v[0] > v[1]) {
            w = max(w, v[1]);
            h = max(h, v[0]);
        }
        else {
            w = max(w, v[0]);
            h = max(h, v[1]);
        }
    }
    
    return w * h;
}