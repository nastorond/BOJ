class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto v : queries) {
            int tmp=arr[v[0]];
            for (int i=v[0]+1; i<=v[1]; i++) {
                tmp ^= arr[i];
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};