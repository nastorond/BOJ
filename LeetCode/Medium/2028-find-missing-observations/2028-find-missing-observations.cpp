class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (n + m) * mean;
        int sumOfRolls = 0;
        
        for (int num : rolls) {
            sumOfRolls += num;
        }
        
        int missingSum = totalSum - sumOfRolls;
        
        if (missingSum < n || missingSum > n * 6) {
            return {};
        }
        
        vector<int> result(n, 1);
        missingSum -= n;
        
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add = min(5, missingSum);
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};
