class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& temp, int start) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            backtrack(nums, temp, i + 1);
            temp.pop_back();  // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp, 0);
        return result;
    }
};
