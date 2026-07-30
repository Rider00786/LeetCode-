class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8){ // edge case 
            return n;
        }   

        int count_group = n - 8;
        int i = 2; 
        int ans = 8;

        while(count_group >= 8){
            ans += 8*i;
            i++;
            count_group -= 8;
        }

        ans += i*count_group;
        return ans;
    }
};