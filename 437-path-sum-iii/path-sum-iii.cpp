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
    void findPath(TreeNode* root, int target, long sum, int& cnt) {
        if(root == NULL)    return;
        if(sum + root->val == target)   cnt++;

        findPath(root->left, target, sum + root->val, cnt);
        findPath(root->right, target, sum + root->val, cnt);
    }
    
    void totPath(TreeNode* root, int target, int& total) {
        if(root == NULL)    return;

        int cnt = 0;
        findPath(root, target, 0, cnt);
        total += cnt; 
        // cout << root->val << " : " << total << endl;
        
        totPath(root->left, target, total);
        totPath(root->right, target, total);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int total = 0;
        totPath(root, targetSum, total);
        return total;
    }
};