class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            xor1 ^= i;
            xor2 ^= nums[i];
        }
        xor1 ^= n; // XOR with the last number in the range [0, n]
        
        return xor1 ^ xor2;
    }
};
