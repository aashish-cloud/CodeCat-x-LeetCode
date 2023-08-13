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
    pair<int, int> helper(TreeNode* root, int &diff) {
        if(root->left == NULL && root->right == NULL)   return {root->val, root->val};

        pair<int, int> left = {INT_MAX, INT_MIN};
        if(root->left)
            left = helper(root->left, diff);
        
        pair<int, int> right = {INT_MAX, INT_MIN};
        if(root->right)        
            right = helper(root->right, diff);

        int mini = min(left.first, right.first);
        int maxi = max(left.second, right.second);

        diff = max(diff, max(abs(root->val - mini), abs(root->val - maxi)));

        return {min(mini, root->val), max(maxi, root->val)};
    }

    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;

        helper(root, diff);
        return diff;
    }
};