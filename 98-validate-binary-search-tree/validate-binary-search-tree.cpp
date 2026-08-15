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
private: 
    bool isvalid(TreeNode* r , long long mi , long long ma){
        if(!r)return true;
        if(r->val <= mi || r->val >= ma)return false;
        return isvalid(r->left , mi , r->val) && isvalid(r->right , r->val , ma);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root , LLONG_MIN , LLONG_MAX);
    }
};