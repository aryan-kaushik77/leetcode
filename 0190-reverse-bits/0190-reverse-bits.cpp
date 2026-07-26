class Solution {
public:
    int reverseBits(int n) {
      uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            // Shift answer left to make space
            ans <<= 1;

            // Copy the last bit of n into ans
            ans |= (n & 1);

            // Remove the processed bit from n
            n >>= 1;
        }

        return ans;  
    }
};