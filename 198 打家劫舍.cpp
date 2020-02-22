class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev_max = 0;
        int preprev_max = 0;
        for(int i=0;i<nums.size();i++)
        {
            int temp = prev_max;
            prev_max = max(prev_max , preprev_max + nums[i]);
            preprev_max = temp;
        }
        return prev_max;
    }
};
