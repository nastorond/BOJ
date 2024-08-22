class Solution {
public:
    unsigned int findComplement(unsigned int num) {
        
        unsigned int mask = ~0;
        
        while (num & mask) {
            mask <<= 1;
        }
        
        return ~mask & ~num;
    }
};