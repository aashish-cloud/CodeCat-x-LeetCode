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
    void flat(TreeNode* root, TreeNode* &list, TreeNode* &cursor) {
        if(root == NULL)    return;
        
        TreeNode* node = new TreeNode(root->val);
        node -> left = NULL;
        node -> right = NULL;

        if(list == NULL) {
            list = node;
            cursor = node;
        } else {
            cursor->right = node;
            cursor = cursor->right;
        }

        flat(root->left, list, cursor);
        flat(root->right, list, cursor);
    }

    void flatten(TreeNode* root) {
        TreeNode* list = NULL;
        TreeNode* cursor = NULL;
        
        flat(root, list, cursor);

        cursor = list;
        TreeNode* cursor1 = root;

        while(cursor) {
            cursor1->left = NULL;
            cursor1->right = cursor->right;

            cursor1 = cursor1->right;
            cursor = cursor->right;
        }
    }
};