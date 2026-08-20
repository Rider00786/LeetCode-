class Solution {
public:
    void helper(vector<int>& nums ,vector<vector<int>>& ans ,vector<int>& temp , int i , int target ){
       
        if(i == nums.size() || target < 0){
            return;
        }
        if( target == 0){
            ans.push_back({temp});
            return;
        }


        // single inclusion 
        temp.push_back(nums[i]);

        // helper(nums , ans , temp, i+1,  target - nums[i]);
        
        helper(nums , ans , temp, i,  target - nums[i]);

        temp.pop_back();

        helper(nums , ans , temp, i+1, target );
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums , ans , temp, 0,  target);

        return ans;
    }
};