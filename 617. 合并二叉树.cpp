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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root = recurse(t1,t2);
        return root;
    }

    TreeNode* recurse(TreeNode *node1, TreeNode *node2)
    {
        if(!node1 && !node2)
            return nullptr;
        TreeNode *temp = new TreeNode((!node1?0:node1->val) + (!node2?0:node2->val));
        temp->left = recurse(!node1?nullptr:node1->left, !node2?nullptr:node2->left);
        temp->right = recurse(!node1?nullptr:node1->right, !node2?nullptr:node2->right);
        return temp;
    }
};
