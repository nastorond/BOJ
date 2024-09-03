class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sumOfReq = 0;
        for (int num : chalk) {
            sumOfReq += num;
        }
        
        k %= sumOfReq;
        
        for (int i=0; i<chalk.size(); i++) {
            k -= chalk[i];
            if (k<0) return i;
        }
        
        return 0;
    }
};