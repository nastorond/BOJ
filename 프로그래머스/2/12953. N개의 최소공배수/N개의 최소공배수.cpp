#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    answer = arr[0];
    for (int i=1; i<arr.size(); i++) {
        int g = gcd(answer, arr[i]);
        int l = answer*arr[i]/g;
        answer = l;
    }
    
    return answer;
}