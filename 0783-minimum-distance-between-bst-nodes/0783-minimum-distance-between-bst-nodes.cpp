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
    TreeNode* prev = nullptr ; // to track prev value for comparison
    
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return INT_MAX;

        int ans = INT_MAX;
        // left subtree
        if(root->left){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans , leftMin);
        }    

        // root 
        if(prev != nullptr){ // otherwise subtraction error;
            ans = min(ans , (root->val - prev->val)); // always a positive number
        }
        prev = root;

        // right
        if(prev->right){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans , rightMin);
        }

        return ans;

    }
};