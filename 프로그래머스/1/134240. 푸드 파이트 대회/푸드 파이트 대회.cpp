#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i=1; i<food.size(); i++) {
        if (food[i] == 1) continue;
        
        for (int j=0; j<food[i]/2; j++) {
            answer += to_string(i);
        }
    }
    string tmp = answer;
    reverse(tmp.begin(), tmp.end());
    
    return answer + '0' + tmp;
}