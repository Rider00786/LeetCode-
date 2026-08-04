class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin() , nums.end());

        int Min = INT_MAX;
        int Max = INT_MIN;

        for(int val : nums){
            if( val > Max ) Max = val;
            if(val < Min)  Min = val;
        }
        
        int idx =0;
        for(int i =Min ;  i<=Max ; i++){
            if(nums[idx] != i){
                ans.push_back(i);
            }
            else{
                idx++;
            }
        }

        return ans;
    }
};