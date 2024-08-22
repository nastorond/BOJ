class Solution {
public:
    unsigned int findComplement(unsigned int num) {
        
        if (num == 1) return 0;
        
        unsigned int bit = log2(num) + 1;
        unsigned int mask = (1U << bit) - 1;
        
        return num^mask;
    }
};