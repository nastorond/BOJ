class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> hashing;
        int res = 0;
        
        for (char c: allowed) {
            hashing.insert(c);    
        }
        
        for (string s : words) {
            int cnt=0;
            for (char c: s) {
                if (hashing.count(c)) cnt++;
            }
            if (cnt == s.size()) res++;
        }
        
        return res;
    }
};