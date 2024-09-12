class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(auto i:allowed) {
            st.insert(i);
        }
        int count = 0;
        for(auto i: words) {
            bool consistent = true;
            for(auto ch: i){
                if(st.find(ch) == st.end()) {
                    consistent = false;
                    break;
                }
            }
            if(consistent) count ++;
        }
        return count;
    }
};