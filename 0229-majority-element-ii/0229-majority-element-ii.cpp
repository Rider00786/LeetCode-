class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int totalCount = n/3;

        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = 0 ; i<n ; i++){
            m[nums[i]]++;
        }

        for(auto it : m){
            if(it.second > totalCount){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};