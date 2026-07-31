class Solution {
public:
    int minimumPushes(string s) {
        int n = s.size();

    
        vector<int> freq(26,0); // so that we can sort them
        int count = 1;

        for(int i =0 ; i<n; i++){
            freq[s[i] - 'a']++;
        }

        sort(freq.rbegin() , freq.rend());

        int clicks = 1;
        int ans = 0;

        for(int i=0 ; i<freq.size() ; i++){
            if(freq[i] == 0) break;

            if(i != 0 && i%8 == 0){
                clicks++;
            }
            ans += clicks*freq[i];
        }

        return ans;

    }
};