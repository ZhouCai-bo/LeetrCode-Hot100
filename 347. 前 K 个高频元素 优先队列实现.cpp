struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        unordered_map<int,int> m;
        vector<int> res;
        for(auto a: nums)
            m[a]++;
        for(auto a: m)
            q.push(a);
        while(k--)
        {
            auto elem = q.top();
            q.pop();
            res.push_back(elem.first);
        }
        return res;
    }
};
