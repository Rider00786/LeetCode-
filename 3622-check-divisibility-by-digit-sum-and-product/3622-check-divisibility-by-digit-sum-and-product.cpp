class Solution {
public:
    bool checkDivisibility(int n) {
        
        long long  sum = 0;
        long long product = 1;
        int num = n;

        while( num > 0 ){

            long long rem = num%10;
            sum += rem;
            product = product*rem;
            num = num/10;
        }

        return n%(sum+product) == 0;
    }
};