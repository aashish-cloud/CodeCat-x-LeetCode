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
    bool findParents(TreeNode* root, TreeNode* target, vector<TreeNode*> &parents) {
        if(root == NULL)
            return false;

        if(root == target)
            return true; 
        
        parents.push_back(root);
        
        if(findParents(root->left, target, parents))    return true;
        if(findParents(root->right, target, parents))   return true;

        parents.pop_back();

        return false;
    }

    bool findTarget(TreeNode* root, TreeNode* target) {
        if(root == NULL)
            return false;

        if(root == target)
            return true;
        
        if(findTarget(root->left, target))  return true;
        if(findTarget(root->right, target))  return true;
        
        return false;
    }

    void findK(TreeNode* root, vector<int> &ans, int dis, int cnt) {
        if(root == NULL)    return;

        if(cnt == dis) {
            ans.push_back(root->val);
            return;
        }

        findK(root->left, ans, dis, cnt + 1);
        findK(root->right, ans, dis, cnt + 1);        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        findK(target, ans, k, 0);

        vector<TreeNode*> parents;
        findParents(root, target, parents);
        
        int n = parents.size();
        for(int i = n - 1; i >= 0; i--) {
            int rem_lvl = k - (n - i); 
            
            if(rem_lvl > 0) {
                findTarget(parents[i]->left, target) ? findK(parents[i]->right, ans, k, n - i + 1) :
                findK(parents[i]->left, ans, k, n - i + 1);
            }

            if(rem_lvl == 0) {
                ans.push_back(parents[i]->val);
                break;
            }
        }

        return ans;
    }
};