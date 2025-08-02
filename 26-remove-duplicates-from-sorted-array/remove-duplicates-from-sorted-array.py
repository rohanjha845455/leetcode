class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums.sort()
        seen = set()
        i = 0
        for num in nums:
            if num not in seen:
                seen.add(num)
                nums[i] = num
                i += 1
        return i
        unique = list(set(nums))        
        nums[:len(unique)] = unique     
        return len(unique)