#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            ret |= n >> i << 31 >> i;
        }
        return ret;
    }
};