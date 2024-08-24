#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<pair<string, bool>>> travel;
vector<string> answer;
int cnt;

void dfs(string cur_loc, vector<string> &trip) {
    if (answer.size() > 1) return ;
    if (trip.size() == cnt+1) {
        answer = trip;
        return ;
    }
    for (auto it=travel[cur_loc].begin(); it != travel[cur_loc].end(); it++) {
        if (it->second == false) {
            it->second = true;
            trip.push_back(it->first);
            dfs(it->first, trip);
            trip.pop_back();
            it->second = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i=0; i<tickets.size(); i++) {
        cnt++;
        if (travel.count(tickets[i][0]) > 0) {
            travel[tickets[i][0]].push_back(make_pair(tickets[i][1], false));
        } else {
            vector<pair<string, bool>> tmp;
            tmp.push_back(make_pair(tickets[i][1], false));
            travel[tickets[i][0]] = tmp;
        }
    }
    
    for (auto it=travel.begin(); it!=travel.end(); it++) {
        sort(travel[it->first].begin(), travel[it->first].end());
    }
    
    vector<string> tmp;
    tmp.push_back("ICN");                                       
    dfs("ICN", tmp);
    
    return answer;
}