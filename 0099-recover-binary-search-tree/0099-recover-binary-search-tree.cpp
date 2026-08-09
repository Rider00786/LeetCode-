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
    TreeNode* prev = nullptr;
    TreeNode* First = nullptr;
    TreeNode* Second = nullptr;

    void findNodes(TreeNode* root){

        if(root == nullptr){
            return;
        }

        findNodes(root->left);
         
        // check if the prev exists
        if(prev != nullptr && root->val < prev->val){
            // it handles both : two pair and a single pair case
            if(First == nullptr){ 
                First = prev;
            }
            Second = root;
        }   
        prev = root; // prev is unique for every index 

        findNodes(root->right);
        
    }

    void swapNodes(TreeNode* root){
        if(root == nullptr){
            return;
        }

        if(root->val == Second->val){
            root->val = First->val;
        }
        else if(root->val == First->val){
            root->val == Second->val;
        }

        swapNodes(root->left);
        swapNodes(root->right);
    }

    void recoverTree(TreeNode* root) {
        // try It in a array : its same as that
        // find the two : swaped nodes : and store it in First and Second pointer
        // swap them using a traversal
        findNodes(root);
         
        int temp = First->val;
        First->val = Second->val;
        Second->val = temp;
    }  
};