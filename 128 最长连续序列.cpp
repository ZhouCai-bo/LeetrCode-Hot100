class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int max_len=0;
        for(int num:nums)
        {
            if(hash.count(num-1))
                continue;
            int len=1;
            while(hash.count(num++ + 1))
                ++len;
            max_len=max(max_len,len);
        }
        return max_len;
    }
};
