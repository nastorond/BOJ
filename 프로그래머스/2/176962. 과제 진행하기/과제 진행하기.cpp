#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stack>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    vector<tuple<int, int, int, string>> sorted_vector;
    for (int i=0; i<plans.size(); i++) {
        
        int tmp_h = stoi(plans[i][1].substr(0, 2));
        int tmp_m = stoi(plans[i][1].substr(3, 2));
        sorted_vector.push_back(make_tuple(tmp_h, tmp_m, stoi(plans[i][2]), plans[i][0]));
    }
    
    sort(sorted_vector.begin(), sorted_vector.end());
    
    stack<tuple<int, int, int, string>> st;
    for (int i=0; i<sorted_vector.size(); i++) {
        if (st.empty()) st.push(sorted_vector[i]);
        else {
            tuple<int, int, int, string> tmp1, tmp2;
            tmp1 = st.top(); st.pop();
            tmp2 = sorted_vector[i];
            
            int tm = (get<0>(tmp2)-get<0>(tmp1)) * 60 + (get<1>(tmp2)-get<1>(tmp1)) - get<2>(tmp1);
            if (tm >= 0) {
                answer.push_back(get<3>(tmp1));
                while (tm > 0 && !st.empty()) {
                    // cout << tm << "\n";
                    if (tm - get<2>(st.top()) >= 0) {
                        tm -= get<2>(st.top());
                        answer.push_back(get<3>(st.top()));
                        st.pop();
                    } else if (!st.empty()) {
                        tuple<int, int, int, string> tmp3 = st.top();
                        st.pop();
                        st.push(make_tuple(get<0>(tmp3), get<1>(tmp3), get<2>(tmp3)-tm, get<3>(tmp3)));
                        break;
                    }
                }
                st.push(tmp2);
            }
            else {
                st.push(make_tuple(get<0>(tmp1), get<1>(tmp1), -tm, get<3>(tmp1)));
                st.push(tmp2);
            }
        }
    }
    
    while (!st.empty()) {
        answer.push_back(get<3>(st.top()));
        st.pop();
    }
    
    return answer;
}