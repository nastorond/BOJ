class Solution {
public:
    int getLucky(string s, int k) {
        string conv2Dig = "";
        for (char c: s) {
            conv2Dig += to_string(c-'a'+1);
        }
        
        while (k > 0) {
            int tmp = 0;
            for (char c: conv2Dig) {
                tmp += c - '0';
            }
            conv2Dig = to_string(tmp);
            k--;
        }
        
        return stoi(conv2Dig);
    }
};