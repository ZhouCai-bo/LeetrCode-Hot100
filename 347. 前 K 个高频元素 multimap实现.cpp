class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_multimap<int,int> mmap;
        unordered_map<int,int> freq;
        vector<int> res;
        for(auto a:nums)
            freq[a]++;
        for(auto a:freq)
            mmap.insert(make_pair(a.second,a.first));
        for(int i=nums.size();i>0;i--)
        {
            auto range = mmap.equal_range(i);
            auto start = range.first;
            if(start!=mmap.end())
            {
                while(start!=range.second && k!=0)
                {
                    res.push_back(start->second);
                    start++;
                    k--;
                }
            }
        }
        return res;
    }
};
