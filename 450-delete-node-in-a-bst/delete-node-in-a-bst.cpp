/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* findleftmost(TreeNode* r) {
        if (!r->left)
            return r;
        return findleftmost(r->left);
    }
    TreeNode* helper(TreeNode* r){
        if(!r->left)return r->right;
        else if(!r->right)return r->left;
        TreeNode* le=r->left;
        TreeNode* leftmostofrightsubtree=findleftmost(r->right);
        leftmostofrightsubtree->left=le;
        return r->right;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if (root->val == key)
            return helper(root);
        TreeNode* t = root;
        while (root) {
            if (root->val < key) {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else
                    root = root->right;
            } else {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else
                    root = root->left;
            }
        }
        return t;
    }
};