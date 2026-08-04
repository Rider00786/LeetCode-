class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        
        unordered_set<int> s;

        int Min = INT_MAX;
        int Max = INT_MIN;

        for(int val : nums){
            Min = min(Min , val);
            Max = max(Max , val);
            
            s.insert(val); // insertion
        }
        
        int idx =0;
        for(int i =Min +1 ;  i<Max ; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};