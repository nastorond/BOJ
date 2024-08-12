class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int i, j, cnt1, cnt2, res=0;
        int row=mat.size(), col=mat[0].size();
        if (row == 0) return 0;
        vector<vector<int>> arr(row, vector<int>(col));

        for (i=0; i<row; i++) arr[i][0] = mat[i][0] - '0';

        for (i=0; i<col; i++) arr[0][i] = mat[0][i] - '0';

        for (i=1; i<row; i++) {
            for (j=1; j<col; j++) {
                if (mat[i][j] == '1') arr[i][j] = min({arr[i][j-1], arr[i-1][j], arr[i-1][j-1]}) + 1;
            }
        }

        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                if (mat[i][j] == '1') {
                    cnt1 = arr[i][j] * arr[i][j];
                    cnt2 = arr[i][j] * arr[i][j];
                    for (int k=i+1; k<row && arr[i][j] <= arr[k][j] && arr[k][j]; k++) cnt1 += arr[i][j];
                    for (int l=j+1; l<col && arr[i][j] <= arr[i][l] && arr[i][l]; l++) cnt2 += arr[i][j];
                    res = max({cnt1, cnt2, res});
                }
            }
        }

        return res;
    }
};