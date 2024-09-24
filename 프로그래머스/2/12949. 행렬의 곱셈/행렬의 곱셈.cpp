#include <string>
#include <vector>

using namespace std;

int getVal(int x, int y, vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
    int res=0;
    
    for (int k = 0; k < arr1[0].size(); k++) {
        res += arr1[x][k] * arr2[k][y];
    }
    
    return res;    
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.resize(arr1.size(), vector<int>(arr2[0].size(), 0));
    
    for (int i=0; i<answer.size(); i++) {
        for (int j=0; j<answer[0].size(); j++) {
            answer[i][j] = getVal(i, j, arr1, arr2);
        }
    }
    
    
    return answer;
}