#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int num: arr) {
        if (answer[answer.size()-1] == num) continue;
        answer.push_back(num);
    }

    return answer;
}