class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        if(nums.size() == 2){
            return (nums[0]-1)*(nums[1]-1);
        }
        int first = 0;
        int second = 0;

        int firstidx = -1;
        for(int i = 0 ; i<n ; i++){
            if(nums[i]> first){
                first = nums[i];
                firstidx = i; 
            }
        }
        for(int i = 0 ; i<n ; i++){
            if( i!=firstidx && nums[i] <= first && nums[i] > second){
                second = nums[i];
            }
        }

        return (first-1)*(second-1);
    }

};