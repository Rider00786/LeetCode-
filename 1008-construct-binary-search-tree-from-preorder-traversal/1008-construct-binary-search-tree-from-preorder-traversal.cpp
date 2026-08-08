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

    TreeNode* helper(vector<int>& preOrder , int &idx , int bound){
        if(idx >= preOrder.size() || preOrder[idx] > bound){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preOrder[idx]);
        idx++;

        root->left = helper(preOrder , idx , root->val);
        root->right = helper(preOrder , idx , bound); // its bound is same as the root itself

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0; // bcz its pass by refrence 
        return helper(preorder , idx , INT_MAX);
    }
};