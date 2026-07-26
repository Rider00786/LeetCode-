class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1= 0,count2 = 0;
        int can1 = 0 ,can2 = 0;

        for(int val : nums){

            if(val == can1) count1++;
            else if(val == can2) count2++;
            else if(count1 ==0 ){
                can1 = val;
                count1 = 1;
            }
            else if(count2 == 0){
                can2 = val;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1= 0,count2 =0;
        for(int val : nums){
            if(val == can1) 
                count1++;
            else if(val == can2) 
                count2++;
        }

        vector<int> ans;

        if(count1 > nums.size()/3){
            ans.push_back(can1);
        }
        if (can1 != can2 && count2 > nums.size()/3){
            ans.push_back(can2);
        }

        return ans;
    }
};