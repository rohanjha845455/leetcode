class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n=len(nums)
        st = 0
        for i in range( n):
            if nums[i]%2==0:
                nums[i], nums[st] = nums[st], nums[i]
                st+=1
        return nums
