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
    int kthSmallest(TreeNode* root, int k) {
        // do a morris traversal and we can do it by other traversal

        TreeNode* t= root;
        int cnt=0;
        int ans=-1;
        while(t){
            if(!t->left){
                if(++cnt == k) ans=t->val;
                t=t->right;
            }
            else{
                TreeNode* l=t->left;
                while(l->right && l->right!=t){
                    l=l->right;
                }

                if(!l->right ){l->right = t;
                    t=t->left;}
                else if(l->right == t ){l->right=nullptr;
                    if(++cnt == k) ans=t->val;
                    t=t->right;
                    }
            }
        }
        return ans;
    }
};