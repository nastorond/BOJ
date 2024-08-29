#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int cnt_zeros = count(lottos.begin(), lottos.end(), 0);
    int cnt_matches = 0;

    for (int num : lottos) {
        if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end()) {
            cnt_matches++;
        }
    }
    
    int max_rank = 7 - (cnt_matches + cnt_zeros);
    int min_rank = 7 - cnt_matches;

    if (max_rank > 6) max_rank = 6;
    if (min_rank > 6) min_rank = 6;

    return {max_rank, min_rank};
}
