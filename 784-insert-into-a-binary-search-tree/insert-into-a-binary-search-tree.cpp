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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode* t=root;
        TreeNode * n=new TreeNode(val);
        while(t){
            if(t->val < val){
                if(t->right){t=t->right;}
                else{t->right = n;
                break;}
            }
            else{
                if(t->left){t=t->left;}
                else{t->left = n;
                break;}
            }
        }
        return root;
    }
};