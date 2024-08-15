#include <string>
#include <vector>

using namespace std;

int cal (int arr[102][102], int idx, int n) {
    int res = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i][idx] || arr[idx][i]) res++;
    }
    
    return res;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[102][102];

    for (int i=1; i<=n; i++) {
        fill(arr[i], arr[i]+n+1, 0);
    }
    
    for (int i=0; i<results.size(); i++) {
        arr[results[i][0]][results[i][1]] = 1;
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (!arr[i][j] && arr[i][k] && arr[k][j]) {
                    arr[i][j] = 1;
                }
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        answer += cal(arr, i, n) == n-1 ? 1 : 0;
    }
    
    return answer;
}