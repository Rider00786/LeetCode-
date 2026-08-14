class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> m;
        unordered_set<int> s;

        int n = arr.size();

        for(int i = 0 ; i<n ; i++){
            if(m.find(arr[i]) == m.end()){
                m[arr[i]] = 1;
            }
            m[arr[i]]++;
        }

        for(auto &[key, value] : m){
            if(s.find(value) != s.end()){
                return false;
            }
            s.insert(value);
        }

        return true;
    }
};