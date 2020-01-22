class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> tags(numCourses, 0);

        for(int i=0; i<numCourses; i++)
        {
            if(!dfs(numCourses, tags, prerequisites, i))
                return false;
        }

        return true;
    }

    bool dfs(int numCourses, vector<int> & tags, vector<vector<int>>& prerequisites, int index)
    {
        if(tags[index] == 1)
            return false;
        if(tags[index] == -1)
            return true;
        tags[index]=1;

        for(auto a: prerequisites)
        {
            if(a[0] == index && !dfs(numCourses, tags, prerequisites, a[1]))
                return false;
                
        }

        tags[index]=-1;
        return true;
    }
};
