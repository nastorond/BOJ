#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    int loc;
    for (int i=0; i<seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            loc = i;
            break;
        }
    }
    
    answer += "김서방은 " + to_string(loc) + "에 있다";
    
    return answer;
}