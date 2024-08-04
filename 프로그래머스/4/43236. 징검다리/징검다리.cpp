#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int left = 0, right = distance;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int prev = 0, cnt = 0;
        for (int i=0; i<rocks.size(); i++) {
            if (rocks[i] - prev < mid)
                cnt++;
            else 
                prev = rocks[i];
        }
        
        if (distance - prev < mid) cnt++;
        
        if (cnt <= n) {
            left = mid+1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}