class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left; // Need a larger number
                } else {
                    --right; // Need a smaller number
                }
            }
        }

        return result;
    }
};
