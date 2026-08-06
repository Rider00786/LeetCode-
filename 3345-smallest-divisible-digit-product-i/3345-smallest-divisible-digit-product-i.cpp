class Solution {
public:
    int product(int n){
        int prod = 1;

        while(n > 0){
            int rem = n%10;
            prod *= rem;
            n = n/10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {

        int ans = n;
        while(true){
            int curr_prod = product(ans);
            if(curr_prod%t == 0){
                break;
            }
            ans+=1;
        }
        return ans;
    }
};