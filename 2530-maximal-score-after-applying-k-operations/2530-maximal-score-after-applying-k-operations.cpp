class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto i:nums) {
            pq.push(i);
        }
        long long ans = 0;
        while(k--) {
            int val = pq.top();
            pq.pop();
            ans +=1LL*val;
            pq.push(ceil((double)val / 3));
        }
        return ans;
    }
};