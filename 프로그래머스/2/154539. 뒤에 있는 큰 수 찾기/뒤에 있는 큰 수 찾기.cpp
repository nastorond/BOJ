#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define MAXV 1000005

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    answer.push_back(-1);
    st.push(*(numbers.end() - 1));
    for (auto it = numbers.end()-2; it != numbers.begin()-1; it--) {
        if (st.top() > *it) {
            answer.push_back(st.top());
            st.push(*it);
        } else {
            while (!st.empty()) {
                if (st.top() > *it) {
                    answer.push_back(st.top());
                    st.push(*it);
                    break;
                }
                st.pop();
            }
            if (st.empty()) {
                st.push(*it);
                answer.push_back(-1);
            }
        }
    }
        
    reverse(answer.begin(), answer.end());
    
    return answer;
}