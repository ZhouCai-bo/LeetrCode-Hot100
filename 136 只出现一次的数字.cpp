class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        if(nums.size()==1)
            return ans;
        for(int i=1;i<nums.size();i++)
            ans^=nums[i];
        return ans;
    }
};
