#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<int, string>> genre_cnt;
    map<string, int> genre_play_cnt;
    map<string, priority_queue<pair<int, int>>> songs;
    
    for (int i=0; i<genres.size(); i++) {
        genre_play_cnt[genres[i]] += plays[i];
        songs[genres[i]].push(make_pair(plays[i], -i));
    }
    
    for (auto it = genre_play_cnt.begin(); it!=genre_play_cnt.end(); it++) {
        genre_cnt.push_back(make_pair(it->second, it->first));
    }
    
    sort(genre_cnt.begin(), genre_cnt.end());
    reverse(genre_cnt.begin(), genre_cnt.end());

    for (int i=0; i < genre_cnt.size(); i++) {
        string gen_name = genre_cnt[i].second;

        int cnt = 0, len = songs[gen_name].size();
        for (int j=0; j<len; j++) {
            answer.push_back(-songs[gen_name].top().second);
            songs[gen_name].pop();
            cnt += 1;
            if (cnt == 2) break;  
        }
    }
    
    return answer;
}