#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, i=0, j=people.size()-1, now=0;
    
    sort(people.begin(), people.end());
    
    while (i<=j) {
        if (people[i] + people[j] <= limit)
            i++;
        j--;
        answer++;
    }

    return answer;
}