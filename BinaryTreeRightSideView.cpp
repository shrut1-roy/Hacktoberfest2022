/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void func(TreeNode *root, vector<int>&ans, int level) {
        if(root==NULL) return;
        if(ans.size()==level) 
            ans.push_back(root->val);
        level++;
        func(root->right, ans, level);
        func(root->left, ans, level);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        int level = 0;
        func(root, ans, level);
        return ans;
    }
};
