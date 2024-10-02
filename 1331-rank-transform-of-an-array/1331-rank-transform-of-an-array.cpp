class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<pair<int,int>>curr;
        for(int i=0;i<arr.size();i++) {
            curr.push_back({arr[i],i});
        }
        sort(curr.begin(), curr.end());

        vector<int>v(arr.size(),1);
        for(int i=1;i<arr.size();i++) {
            if(curr[i].first == curr[i-1].first) v[curr[i].second] = v[curr[i-1].second];
            else v[curr[i].second] = v[curr[i-1].second] + 1;
        }
        return v;
    }
};