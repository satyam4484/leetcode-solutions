class Solution {
public:
    bool isCommonPrefix(int mid , vector<string>&strs) {
        string initial = strs[0].substr(0,mid);
        for(int i=1;i<strs.size();i++) {
            string curr = strs[i];
            if(curr.compare(0,mid,initial)!=0) {
                return false;
            }
        }
        return true ;

    }
    string longestCommonPrefix(vector<string>& strs) {
        int minans = INT_MAX;
        for(auto &s: strs)  {
            minans = min(minans,(int)s.size());
        }

        int low = 1,high = minans;
        while(low <= high) {
            int mid = (low + high) /2;
            if(isCommonPrefix(mid,strs)) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
};