class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // sum of largest Sequential prefix
        // return the value >= sum which is not in array
        int sum = nums[0];
        int ans = sum;
        
        unordered_set<int> s;
        s.insert(nums[0]);

        int i = 1;
        for( i ; i<nums.size() ; i++){   
            // if(sum == 0) sum += nums[i-1];

            if(nums[i] == (nums[i-1] + 1)){
                sum += nums[i];
            }else{
                // ans = max(ans,sum);
                break;
            }
            ans = max(ans,sum);
            s.insert(nums[i]);
        }

        for(i ; i<nums.size() ; i++){
            s.insert(nums[i]);
        }


        while(true){
            if(s.find(ans) == s.end()){
                return ans;
            }
            ans++;
        }

        return ans;
    }
};