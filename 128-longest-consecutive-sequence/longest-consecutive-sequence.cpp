class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        // Use a set to store the unique elements
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};