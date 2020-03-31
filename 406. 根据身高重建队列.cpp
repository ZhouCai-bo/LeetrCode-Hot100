class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),
        [](vector<int> &p1, vector<int> &p2){
            return p1[0]==p2[0] ? p1[1]<=p2[1] : p1[0]>p2[0];
        });
        list<vector<int>> l;
        for(int i=0; i<people.size(); i++)
        {
            auto ite=l.begin();
            advance(ite, people[i][1]);
            l.insert(ite, people[i]);
        }
        return vector<vector<int>>(l.begin(), l.end());
    }
};
