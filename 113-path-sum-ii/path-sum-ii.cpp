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
    void findPath(TreeNode* root, int sum, int target, vector<int> &list, vector<vector<int>>& ans) {
        if(root->left == NULL && root->right == NULL) {
            if(sum + root->val == target) {
                list.push_back(root->val);
                ans.push_back(list);
                list.pop_back();
            }

            return;
        }

        if(root->left) {
            list.push_back(root->val);
            findPath(root->left, sum + root->val, target, list, ans);
            list.pop_back();
        }

        if(root->right) {
            list.push_back(root->val);
            findPath(root->right, sum + root->val, target, list, ans);
            list.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL)    return ans;
        vector<int> list;

        findPath(root, 0, targetSum, list, ans);
        
        return ans;
    }
};