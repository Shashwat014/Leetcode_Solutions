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
    TreeNode* build(int &i ,vector<int>& p , int bound ){
        if(i==p.size() || p[i] > bound)return nullptr;
        TreeNode* r=new TreeNode(p[i++]);
        r->left = build(i , p , r->val);
        r->right = build(i , p , bound);
        return r;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(i , preorder , INT_MAX);
    }
};