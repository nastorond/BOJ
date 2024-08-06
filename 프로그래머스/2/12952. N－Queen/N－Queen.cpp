#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0, cnt_center = 0;
bool fld[12][12] = {false, };
int mx[] = {-1, -1, -1};
int my[] = {0, 1, -1};

bool condition (int x, int y, int n) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool ck_avail(int x, int y, int n) {
    for (int i=0; i<3; i++) {
        int dx = x, dy = y;
        while (true) {
            dx += mx[i];
            dy += my[i];
            if (condition(dx, dy, n)){
                if (fld[dx][dy]) return false;
            } else break;
        }
    }
    return true;
}

void mono_set_q(int x, int y, int n) {
    for (int y_idx = 0; y_idx < n; y_idx++) {
        if (ck_avail(x, y_idx, n)) {
            if (x == n-1) {
                cnt_center += 1; return ;
            }
            fld[x][y_idx] = true;
            mono_set_q(x+1, y, n);
            fld[x][y_idx] = false;
        }
    }
}

void set_q(int x, int y, int n) {
    if (x == n) return ;
    
    if (x == 0) {
        for (int y_idx = 0; y_idx < n/2; y_idx++) {
            fld[x][y+y_idx] = true;
            set_q(x+1, y, n);
            fld[x][y+y_idx] = false;
        }
        if (n%2) {
            if (n == 1) {
                cnt_center += 1;
                return;
            }
            fld[x][n/2] = 1;
            mono_set_q(x+1, y, n);
        }
    }
    else {
        for (int y_idx=0; y_idx < n; y_idx++) {
            if (ck_avail(x, y_idx, n)) {
                if (x == n-1) {
                    cnt += 1;
                    return;
                }
                else {
                    fld[x][y_idx] = true;
                    set_q(x+1, y, n);
                    fld[x][y_idx] = false;
                }
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    set_q(0, 0, n);
    
    cout << cnt << " " << cnt_center << "\n";
    answer += (2 * cnt) + cnt_center;
    return answer;
}