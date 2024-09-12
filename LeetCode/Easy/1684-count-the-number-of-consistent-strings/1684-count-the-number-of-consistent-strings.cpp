class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {      
        bool arr[26] = {false, };
        int res = 0;
        
        for (char c: allowed) {
            arr[c-'a'] = true;  
        }
        
        for (string s : words) {
            int cnt=0;
            for (char c: s) {
                if (arr[c-'a']) cnt++;
            }
            if (cnt == s.size()) res++;
        }
        
        return res;
    }
};