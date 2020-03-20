/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int size,next_size=1;
        res.push_back(vector<int>{root->val});
        while(next_size!=0)
        {
            size=next_size;
            next_size=0;
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                {
                    temp.push_back(node->left->val);
                    q.push(node->left);
                    next_size++;
                }
                if(node->right)
                {
                    temp.push_back(node->right->val);
                    q.push(node->right);
                    next_size++;
                }
            }
            if(temp.size()!=0)
                res.push_back(temp);
        }
        return res;
    }
};
