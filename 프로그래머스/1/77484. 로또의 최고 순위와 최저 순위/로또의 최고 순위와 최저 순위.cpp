#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int checkNum[6], lim = lottos.size(), score=0, cnt=0;
    memset(checkNum, -1, sizeof(checkNum));
    
    for (int i=0; i<lim; i++) {
        if (lottos[i] == 0) {
            cnt++;
            continue;
        }
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            checkNum[i] = 1;
            score++;
        } else {
            checkNum[i] = 0;
        }
    }
    
    if (score + cnt == 6) {
        answer.push_back(1);
    } else if (score + cnt == 5) {
        answer.push_back(2);
    } else if (score + cnt == 4) {
        answer.push_back(3);
    } else if (score + cnt == 3) {
        answer.push_back(4);
    } else if (score + cnt == 2) {
        answer.push_back(5);
    } else {
        answer.push_back(6);
    }
    
    switch (score) {
        case 6:
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
            break;
    }
        
    
    return answer;
}