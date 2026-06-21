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
    int cnt = 0;
    int res = -1;

    int inorder(TreeNode* root, int k) {
        if(root == nullptr || cnt >= k) return 0;
        inorder(root->left, k);
        cnt++;
        if(cnt == k) {
            res = root->val;
            return res;
        }
        inorder(root->right, k);
        return res;
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = inorder(root, k);
        return res;
    }
};
