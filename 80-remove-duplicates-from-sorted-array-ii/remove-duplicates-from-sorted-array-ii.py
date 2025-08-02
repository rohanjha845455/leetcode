class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        
        
        st=1
        for i in range(2,n):
            if nums[i]!=nums[st-1]:
                st+=1
                nums[st]=nums[i]

        return st+1