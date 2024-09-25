#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i=0; i<speeds.size(); i++) {
        progresses[i] = 100 - progresses[i];
        progresses[i] = progresses[i]%speeds[i] == 0 ? progresses[i]/speeds[i] :(progresses[i]/speeds[i]) + 1;
    }

    int prev=progresses[0], cnt=1;
    for (int i=1; i<progresses.size(); i++) {
        if (prev >= progresses[i]) cnt++;
        else {
            prev = progresses[i];
            answer.push_back(cnt);
            cnt=1;
        }
    }
    
    if (cnt > 0) answer.push_back(cnt);
    return answer;
}