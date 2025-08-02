class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        st=0
        for i in range(1,n):
            if nums[i]!=nums[st]:
                st+=1
                nums[st]=nums[i]

        return st+1
