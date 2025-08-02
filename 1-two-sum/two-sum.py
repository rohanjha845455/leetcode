class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        dict1={}
        for i in range (n):
            rem = target -nums[i]
            if rem in dict1:
                return [dict1[rem],i]
            dict1[nums[i]]=i
        



        