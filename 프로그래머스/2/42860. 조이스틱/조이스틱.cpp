#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0, len = name.size(), move = len;
    int answer_sheet[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for (int i=0; i<len; i++) {
        answer += answer_sheet[name[i] - 'A'];
        int next = i+1;
        while (next < len && name[next] == 'A') next++;
        move = min(move, min(i+i+(len-next), (len-next)*2+i));
    }
    answer += move;
    return answer;
}