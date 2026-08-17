class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = INT_MIN;

        for(int i =0 ; i<words.size() ; i++){
            string s1 = words[i];
            int freq1[26] = {0};

            for(char val : s1){
                freq1[val -'a']++;
            }
            
            for(int j =i+1 ; j<words.size() ; j++){
                string s2 = words[j];
                int freq2[26] = {0};
                bool isequal = true;
                int currmax = 0;

                for(char val : s2){
                    freq2[val -'a']++;
                }
                
                for(int i = 0 ; i<26 ; i++ ){
                    if(freq1[i] != 0 && freq2[i] != 0){
                        isequal = false;
                    }
                }

                if(isequal){
                    currmax = s1.size()*s2.size();
                }

                ans = max(currmax,ans);
            }       

        }


        return ans;
    }
};