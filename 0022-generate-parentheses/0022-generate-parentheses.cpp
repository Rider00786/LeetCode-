class Solution {
public: 
    void helper(vector<string>& ans , int open , int close ,int n, string& str){
        if( str.size() == 2*n){
            ans.push_back(str);
            return;
        }

        if(open < n){
            str.push_back('(');
            helper(ans , open+1 , close ,n , str);
            str.pop_back();
        }

        if(close < open){
            str.push_back(')');
            helper(ans , open , close+1 , n, str);
            str.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans = {};
        string s;
        helper(ans , 0 , 0 ,n , s );

        return ans;
    }
};