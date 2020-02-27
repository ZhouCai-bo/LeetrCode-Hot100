class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int globalmax = INT_MIN, cmax = 1, cmin = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<0)
            {
                int temp = cmax;
                cmax = cmin;
                cmin = temp;
            }
            cmax = max(cmax*nums[i], nums[i]);
            cmin = min(cmin*nums[i], nums[i]);

            globalmax = max(globalmax, cmax);
        }   
        return globalmax;
    }
};
