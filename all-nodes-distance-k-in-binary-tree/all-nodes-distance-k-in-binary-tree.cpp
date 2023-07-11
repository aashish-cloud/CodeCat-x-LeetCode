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
    int distanceTarget(TreeNode* root, TreeNode* target, vector<TreeNode*> &parents) {
        if(root == NULL)
            return 0;

        if(root == target)
            return 1; 
        
        parents.push_back(root);
        
        int left_dis = distanceTarget(root->left, target, parents);
        
        if(left_dis)    return left_dis + 1;
        
        int right_dis = distanceTarget(root->right, target, parents);

        if(right_dis)   return right_dis + 1;
    
        parents.pop_back();

        return 0;
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

        // if(cnt > dis)
        //     return;

        if(cnt == dis) {
            // if(root->val != target) 
                ans.push_back(root->val);
            return;
        }

        findK(root->left, ans, dis, cnt + 1);
        findK(root->right, ans, dis, cnt + 1);        

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        int cnt = 0;

        bool left = false, right = false;

        left = findTarget(root->left, target);
        if(!left)
            right = findTarget(root->right, target);

        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                if(cnt == k)    ans.push_back(t->val);

                if(t->left)     q.push(t->left);
                if(t->right)    q.push(t->right);

                q.pop();
            }

            cnt++;
        }

        for(int num : ans) 
            cout << num << " ";
        cout << endl;

        vector<TreeNode*> parents;
        int dis = distanceTarget(root, target, parents);
        dis--;

        cout << endl << "Parents : " ;
        for(auto i : parents)
            cout << i -> val << " ";
        cout<<endl;

        cout << dis;
        // if(k == dis)
        //     ans.push_back(root->val);

        if(!left && !right)
            return ans;

        int n = parents.size();
        for(int i = n - 1; i >= 0; i--) {
            int level = k - (n - i); 
            
            if(level > 0) {
                findTarget(parents[i]->left, target) ? findK(parents[i]->right, ans, k, n - i + 1) :
                findK(parents[i]->left, ans, k, n - i + 1);
            }

        
            if(level == 0) {
                ans.push_back(parents[i]->val);
                break;
            }
        }

        // if(k > dis) {
            //stay in diff and find
            // left ? findK(root->right, target->val, ans, k - dis, 1) : findK(root->left, target->val, ans, k - dis, 1);
        // } else if(k == dis) {
        //     left ? findK(root->right, target->val, ans, k - dis, 0) : findK(root->left, target->val, ans, k - dis, 0);
        // } else {
            //stay in the same leg
            cout << "here";

            // left ? findK(root->left, target->val, ans, dis - k, 1) : findK(root->right, target->val, ans, dis - k, 1);
        // }

        return ans;
    }
};