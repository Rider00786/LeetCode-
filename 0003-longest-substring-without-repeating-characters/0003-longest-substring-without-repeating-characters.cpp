class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int ans = 0;
        int left = 0;

        for(int right =0 ; right< s.size(); right++){
            while(set.find(s[right]) != set.end()){ // duplicate value still exists
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            ans = max(ans , right - left + 1);
        }

        return ans;
    }
};