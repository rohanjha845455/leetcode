class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int piv = -1;
        //finding pivot
        for(int i = n-2; i >= 0;i--)
        {
             if(nums[i] < nums[i+1])
             {
                 piv = i;//pivot index
                 break;
             }
        } 
        //if not found then revere
        if(piv == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        //finding next larger element
        for(int i = n-1; i > piv ;i--)
        {
            if(nums[i] > nums[piv])
            {
                swap(nums[i],nums[piv]);
                break;
            }
        }
        // reversing from piv+1 to n-1
        reverse(nums.begin()+piv+1,nums.end());
    }
};