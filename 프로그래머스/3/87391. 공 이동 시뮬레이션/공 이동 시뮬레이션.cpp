#include <string>
#include <vector>
#define ll long long

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll answer = 0;
    pair<ll, ll> st = make_pair(x, y), end = make_pair(x, y);
    
    for (int i=queries.size()-1; i >= 0; i--) {
        ll dir = queries[i][0], dis = queries[i][1];
        switch(dir) {
            case 0:
                if (st.second != 0) st.second += dis;
                end.second += dis;
                if (end.second > m-1) end.second = m-1;
                break;
                
            case 1:
                st.second -= dis;
                if (st.second < 0) st.second = 0;
                if (end.second != m-1) end.second -= dis;
                break;
                
            case 2:
                if (st.first != 0) st.first += dis;
                end.first += dis;
                if (end.first > n-1) end.first = n-1;
                break;
            
            case 3:
                st.first -= dis;
                if(st.first < 0) st.first = 0;
                if(end.first != n-1) end.first -= dis;
                break;
        }
        if (st.first < 0 || st.second > m-1 || end.first < 0 || end.second > m-1)
            return answer;
    }
    
    answer = (abs(st.first - end.first) + 1) * (abs(st.second - end.second) + 1);
    
    return answer;
}