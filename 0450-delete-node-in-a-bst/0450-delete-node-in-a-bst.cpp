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

    // left most node in the right subtree
    TreeNode*  InorderSuccessor(TreeNode* root){
        while(root!= nullptr && root->left != nullptr){
            root = root->left;
        } 

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(key < root->val){
            root->left  = deleteNode(root->left , key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // key == root      
            if(!root->left ){
                TreeNode* temp = root->right;
                delete root;
                return temp; // even we dont know the right chilf exists we retun temp
            }
            else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* Is = InorderSuccessor(root->right);
                root->val = Is->val;
                root->right = deleteNode(root->right , Is->val); // the data will always in right 
            }

        }

        return root;
        
    }
};