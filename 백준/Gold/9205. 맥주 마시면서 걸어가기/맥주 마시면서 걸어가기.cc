#include <iostream>
#include <vector>
#include <queue>
#define MAX_VAL 101

using namespace std;

int n, end_x, end_y;
bool flg;
bool visited[MAX_VAL];
vector<pair<int, int>> con_info;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int dx, dy;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        dx = abs(x - end_x);
        dy = abs(y - end_y);
        if (dx + dy <= 1000) {
            flg=true;
            break;
        }

        for (int i=0; i<con_info.size(); i++) {
            dx = abs(x - con_info[i].first);
            dy = abs(y - con_info[i].second);
            if (dx + dy <= 1000 && !visited[i]) { 
                q.push(make_pair(con_info[i].first, con_info[i].second));
                visited[i] = true;
            }                    
        }

    }
}

void init () {
    con_info.clear();
    flg = false;
    for (int i=0; i<=n; i++) {
        visited[i] = false;
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int test_case;

    cin >> test_case;
    for (int tc=1; tc<=test_case; tc++) {
        int start_x, start_y;

        // init
        init();

        // input
        cin >> n;
        cin >> start_x >> start_y;
        int tmp_x, tmp_y;
        for (int i=0; i<n; i++) {
            cin >> tmp_x >> tmp_y;
            con_info.push_back(make_pair(tmp_x, tmp_y));
        }
        cin >> end_x >> end_y;

        bfs(start_x, start_y);

        // output
        if (flg) cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }

    return 0;
}