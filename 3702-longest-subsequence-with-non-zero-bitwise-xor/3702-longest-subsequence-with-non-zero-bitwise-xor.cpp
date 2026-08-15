class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int Xor = 0;

        for(int val : nums){
            Xor = Xor^val;
        }

        if(Xor == 0){
            for(int val : nums){
                if(val != 0){
                    return n-1;
                }
            }
            return 0; // means all elements are O
        }
        
        return n;
    }
};