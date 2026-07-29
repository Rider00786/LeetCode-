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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* Ip = curr->left;  // to track IP for the curr node

                while(Ip->right != nullptr && Ip->right != curr){
                    Ip = Ip->right;
                }

                if(Ip->right == nullptr){
                    Ip->right = curr; // create
                    curr = curr->left;
                }else{
                    Ip->right = nullptr; // destroy
                    ans.push_back(curr->val); // curr value is stored in vector
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};