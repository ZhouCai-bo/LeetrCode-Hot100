class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1 || numCourses == 0)
            return true;
    
        vector<int> inDegree(numCourses, 0);

        for(auto a: prerequisites)
        {
            ++inDegree[a[0]];
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }   
        }

        int done=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ++done;
            for(auto a: prerequisites)
            {
                if(a[1] == curr)
                {
                    if(--inDegree[a[0]] == 0) 
                        q.push(a[0]);
                }
            }
        }

        return done==numCourses;
    }
};
