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
    pair<int, int> helper(TreeNode* root, int &cnt) {
        if(root == NULL)   return {0, 0};

        pair<int, int>  left = helper(root->left, cnt);
        pair<int, int>  right = helper(root->right, cnt);
        
        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;

        if(root->val == sum / n)   cnt++;
        
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
};